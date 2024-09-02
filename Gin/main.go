package main

import (
	"fmt"
	"log"
	"net/http"

	"todoweb/packages"

	"github.com/gin-gonic/gin"
)

var (
	router   *gin.Engine
	database *packages.DataBaseProps
)

func init() {
	router = gin.Default()
	router.Static("/static", "./static")
	router.LoadHTMLGlob("templates/*.html")

	var err error
	database, err = packages.NewDatabaseConnection("postgres", "localhost", "5432", "postgres", "")
	if err != nil {
		log.Fatalf("Error connecting to database: %v", err)
	}
}

func main() {
	router.GET("/", func(c *gin.Context) {
		c.Redirect(http.StatusSeeOther, "/login")
	})

	router.GET("/login", getLogin)
	router.POST("/login", postLogin)
	router.GET("/register", getRegister)
	router.POST("/register", postRegister)
	router.GET("/tasks/:userid", getTasks)
	// router.POST("/addTask/:userid", addTasks)
	router.POST("/addTask/:userid", addTasks)	
	router.POST("/deleteTask/:userid", deleteTasks)

	err := router.Run("localhost:8080")
	if err != nil {
		log.Fatalf("Failed to run server: %v", err)
	}

	fmt.Println("Server is listening...")
}

func getLogin(c *gin.Context) {
	c.HTML(http.StatusOK, "login.html", nil)
}

func postLogin(c *gin.Context) {
	if err := c.Request.ParseForm(); err != nil {
		c.Redirect(http.StatusSeeOther, "/")
		return
	}

	loginForm := packages.NewForm(
		packages.TrimSpace(c.PostForm("uname")), 
		packages.TrimSpace(c.PostForm("pword")),
	)

	authResult, err := database.CheckUserNameAndPassword(loginForm.Username, loginForm.Password)
	if err != nil {
		fmt.Printf("Failed to check user(%s) : %v", loginForm.Username, err)
		c.String(http.StatusInternalServerError, "Internal Server Error")
		return
	}

	if !authResult.IsAuthenticated {
		fmt.Printf("Authentication failed for user %s\n", loginForm.Username)
		data := gin.H{
			packages.ErrorLoginHTML: packages.LoginError,
			"Username":   loginForm.Username,
		}

		c.HTML(http.StatusOK, "login.html", data)
		return
	}

	// Redirect to the tasks page with user ID
	c.Redirect(http.StatusSeeOther, fmt.Sprintf("/tasks/%d", authResult.UserID))
}

func getRegister (c *gin.Context) {
	c.HTML(http.StatusOK, "register.html", nil)
}

func postRegister(c *gin.Context) {
	if err := c.Request.ParseForm(); err != nil {
		c.Redirect(http.StatusSeeOther, "/register")
		return
	}

	registerForm := packages.NewRegisterForm(
		packages.TrimSpace(c.PostForm("uname")), 
		packages.TrimSpace(c.PostForm("pword")), 
		packages.TrimSpace(c.PostForm("re-pword")), 
	)

	var (
		data gin.H
		status int
	)

	exists, err := database.DoesUserExist(registerForm.Username)
	if err != nil {
		fmt.Printf("Failed to check user(%s): %v", registerForm.Username, err)
		c.String(http.StatusInternalServerError, "Internal Server Error")
		return
	}

	if exists {
		data = gin.H{
			packages.ErrorUsernameHTML : packages.UserAlreadyExistError,
			packages.Form : registerForm,
		}
		status = http.StatusOK
	} else if err := packages.IsValidUsername(registerForm.Username); err != nil {
		data = gin.H{
			packages.ErrorUsernameHTML : packages.UsernameContainsSpace,
			packages.Form : registerForm,
		}
		status = http.StatusOK
	} else if registerForm.Password != registerForm.Re_Password {
		data = gin.H{
			packages.ErrorPasswordHTML : packages.PasswordNotMatch,
			packages.Form : registerForm,
		}
		status = http.StatusOK
	} else if err := packages.IsValidPassword(registerForm.Password); err != nil {
		data = gin.H{
			packages.ErrorPasswordHTML : err.Error(),
			packages.Form : registerForm,
		}
		status = http.StatusOK
	} else {
		err = database.CreateNewUser(registerForm.Username, registerForm.Password)
		if err != nil {
			fmt.Printf("Failed to create user %v,\nError: %v\n", registerForm.Username, err)
			c.String(http.StatusInternalServerError, "Internal Server Error")
			return
		}

		c.Redirect(http.StatusSeeOther, "/login")
		return
	}
	
	c.HTML(status, "register.html", data)
}

func getTasks (c *gin.Context) {
	userIDstr := c.Param("userid")
	userID := packages.StrToInt(userIDstr)
	if userID == -1 {
		fmt.Printf("Failed to check user(%s) : %v", userIDstr, packages.ConvertError)
		c.String(http.StatusInternalServerError, "Invalid User ID")
		return
	} 

	UserTasks, err := database.GetTasksFromDatabase(userID)

	if err != nil {
		fmt.Printf("Failed to check user(%s) : %v", userIDstr, packages.GetTaskError)
		c.String(http.StatusInternalServerError, "Internal Server Error")
		return
	}

	usernameByUserId, err := database.GetUsername(userID)
	if err != nil {
		fmt.Printf("Failed to get username for user ID %d: %v", userID, err)
		c.String(http.StatusInternalServerError, "Internal Server Error")
		return
	}

    c.HTML(http.StatusOK, "todoMain.html", gin.H{
        "tasks":  packages.ToDoPassStruct{
			Tasks: UserTasks,
			UserID: userID,
		},
		"Username" : usernameByUserId,
    })
}

func addTasks (c *gin.Context) {
	userIDstr := c.Param("userid")
	userID := packages.StrToInt(userIDstr)
	if userID == -1 {
		fmt.Printf("Failed to check user(%s) : %v", userIDstr, packages.ConvertError)
		c.String(http.StatusInternalServerError, "Invalid User ID")
		return
	} 

	if err := c.Request.ParseForm(); err != nil {
		c.Redirect(http.StatusSeeOther, "/tasks/"+userIDstr)
		return
	}

	task := packages.TrimSpace(c.PostForm("taskTitle"))

	if err := database.AddTask(userID, task); err != nil {
		c.String(http.StatusInternalServerError, "Failed to add task")
		return
	}
	
	c.Redirect(http.StatusFound, "/tasks/"+userIDstr)
}

func deleteTasks (c *gin.Context) {
	userIDstr := c.Param("userid")
	userID := packages.StrToInt(userIDstr)
	if userID == -1 {
		fmt.Printf("Failed to check user(%s) : %v", userIDstr, packages.ConvertError)
		c.String(http.StatusInternalServerError, "Invalid User ID")
		return
	}

	if err := c.Request.ParseForm(); err != nil {
		c.Redirect(http.StatusSeeOther, "/tasks/"+userIDstr)
		return
	}

	taskIDstr := packages.TrimSpace(c.PostForm("taskID"))
	taskID := packages.StrToInt(taskIDstr)
	if taskID == -1 {
		fmt.Printf("Failed to convert task ID(%s): %v\n", taskIDstr, packages.ConvertError)
		c.String(http.StatusInternalServerError, "Invalid Task ID")
		return
	}

	if err := database.DeleteTask(userID, taskID); err != nil {
		fmt.Printf("Failed to delete task(%d): %v\n", taskID, err)
		c.String(http.StatusInternalServerError, "Failed to delete task")
		return
	}

	c.Redirect(http.StatusSeeOther, "/tasks/"+userIDstr)
}