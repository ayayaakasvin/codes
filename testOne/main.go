package main

import (
	"fmt"
	"html/template"
	"log"
	"net/http"
	"project/packages"
	"time"
)

var tpl *template.Template
var tickerTime *time.Ticker
var channelForTicker chan bool
var database *packages.DataBaseProps

func init() {
	tpl = template.Must(template.ParseGlob("templates/*.html"))
	tickerTime = time.NewTicker(5 * time.Second)
	channelForTicker = make(chan bool)

	var err error
	database, err = packages.NewDatabaseConnection(
		"postgres", "localhost", "5432", "postgres", "",
	)
	if err != nil {
		log.Fatalf(" Error of connecting to database")
	}
}

func main() {
	http.Handle("/templates/", http.StripPrefix("/templates/", http.FileServer(http.Dir("templates"))))

	http.HandleFunc("/", login)
	http.HandleFunc("/register", register)
	http.HandleFunc("/registerProcess", registerProcess)
	http.HandleFunc("/hello", hello)

	fmt.Printf("Server has been started...\n")
	go ThreeSecondTicker()

	if err := http.ListenAndServe(":8080", nil); err != nil {
		log.Fatalf("Server failed: %v", err)
	}
	channelForTicker <- true
}

func login (w http.ResponseWriter, r *http.Request) {
	err := tpl.ExecuteTemplate(w, "login.html", nil)
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
	}
}

func hello(w http.ResponseWriter, r *http.Request) {
    if r.Method != "POST" {
        http.Redirect(w, r, "/", http.StatusSeeOther)
        return
    }

    form := packages.NewForm(r.FormValue("uname"), r.FormValue("pword"))

    ok, err := database.CheckUserNameAndPassword(form.Username, form.Password)
    if err != nil {
        fmt.Printf("Failed to check user(%s): %v\n", form.Username, err)
        http.Error(w, "Internal Server Error", http.StatusInternalServerError)
        return
    }

    if ok {
		fmt.Printf("User(%s) authentification is successful\n", form.Username)
        if err := tpl.ExecuteTemplate(w, "hello.html", form); err != nil {
			fmt.Printf("Error executing template: %v", err)
            http.Error(w, err.Error(), http.StatusInternalServerError)
        }
    } else {
		fmt.Printf("Authentication failed for user %s\n", form.Username)
        http.Redirect(w, r, "/", http.StatusUnauthorized)
    }
}

func register (w http.ResponseWriter, r *http.Request) {
	err := tpl.ExecuteTemplate(w, "register.html", nil)
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
	}
}

func registerProcess (w http.ResponseWriter, r *http.Request) {
	if r.Method != "POST" {
		http.Redirect(w, r, "/register", http.StatusSeeOther)
		return
	}

	var user *packages.RegisterForm = packages.NewRegisterForm(r.FormValue("uname"), r.FormValue("pword"),  r.FormValue("re-pword"))

	if user.Password != user.Re_Password {
		http.Error(w, "Passwords do not match", http.StatusBadRequest)
		return
	}

	exists, err := database.DoesUserExist(user.Username)

	if err != nil {
		fmt.Printf("Failed to check user(%s): %v", user.Username, err)
		http.Error(w, "Internal Server Error", http.StatusInternalServerError)
		return
	}

	if exists {
		fmt.Printf("User(%s) already exists\n", user.Username)
		http.Error(w, "User already exists", http.StatusConflict)
		return
	}
	
	err = database.CreateNewUser(user.Username, user.Password)
	if err != nil {
		fmt.Printf("Failed to create user %v,\nError: %v\n", user.Username, err)
		http.Error(w, "Internal Server Error", http.StatusInternalServerError)
		return
	}

	http.Redirect(w, r, "/login", http.StatusSeeOther)
}

func ThreeSecondTicker () {
	for {
		select {
		case <-channelForTicker:
			fmt.Printf("Server has shut down.\n")
			return
		case <- tickerTime.C:
			fmt.Printf("Server is listening...\n")
		}
	}
}