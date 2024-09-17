package main

import (
	"randompasswordWeb/packages"

	randompass "github.com/ayayaakasvin/randompass/password"

	"github.com/gin-gonic/gin"

	"strconv"

	// "fmt"
	"log"
	"net/http"
)

const (
	
)

var (
	router   *gin.Engine
)

func init() {
	router = gin.Default()
	router.LoadHTMLGlob("templates/*.html")
	router.Static("/static", "./static")
}

func main() {
	router.GET("/", func(c *gin.Context) {
		c.Redirect(http.StatusSeeOther, "/randompasswordgenerator")
	})
	router.GET("/randompasswordgenerator", getMainPage)

	router.POST("/generatePassword", postGeneratePassword)

	if err := router.Run("localhost:8080"); err != nil {
		log.Fatalf("Server start error : %v", err)
	}
}

func getMainPage (c *gin.Context) {
	var inputData gin.H = gin.H{
		"InputData" : "Jokerge",
		"WebSiteNaming" : packages.WebSiteNaming,
	}

	c.HTML(http.StatusOK, "GeneratePassword.html", inputData)
}

func postGeneratePassword(c *gin.Context) {
    if err := c.Request.ParseForm(); err != nil {
        c.Redirect(http.StatusSeeOther, "/")
        return
    }

    var (
        lengthOfPassword int
        Upper, Lower, Digit, Special bool
        err error
    )

    if lengthOfPassword, err = strconv.Atoi(c.PostForm("pwLen")); err != nil {
        lengthOfPassword = 8
    }

    Upper = c.PostForm("UpperLatin") != ""
    Lower = c.PostForm("LowerLatin") != ""
    Digit = c.PostForm("Digits") != ""
    Special = c.PostForm("Special") != ""

    var atLeast1Type bool = Upper && Lower && Digit && Special

    typePass := packages.TypeCheckPassConstructor(Upper, Lower, Digit, Special)
    outputPasswordStruct := randompass.CreateRandomPassword(Upper, Lower, Digit, Special, lengthOfPassword)
    stringPasswordToPass := string(outputPasswordStruct.PasswordItself)

    var inputData gin.H = gin.H{
        "StringPassword" : stringPasswordToPass,
        "GeneratedPassword": outputPasswordStruct,
        "UserEnteredLength": outputPasswordStruct.Length,
        "WebSiteNaming":     packages.WebSiteNaming,
        "TypeCheck":         typePass,
        "AtLeastOneType" : atLeast1Type,
    }

    c.HTML(http.StatusOK, "GeneratePassword.html", inputData)
}
