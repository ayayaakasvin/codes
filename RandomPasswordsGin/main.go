package main

import (
	// "randompasswordWeb/packages"

	// randompass "github.com/ayayaakasvin/randompass/password"
	"randompasswordWeb/packages"

	"github.com/gin-gonic/gin"

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
}

func main() {
	router.GET("/", func(c *gin.Context) {
		c.Redirect(http.StatusSeeOther, "/randompasswordgenerator")
	})
	router.GET("/randompasswordgenerator", getMainPage)

	router.POST("/generate", postGeneratePassword)

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

func postGeneratePassword (c *gin.Context) {
	var inputData gin.H = gin.H{
		"InputData" : "Jokerge",
		"WebSiteNaming" : packages.WebSiteNaming,
	}

	c.HTML(http.StatusOK, "GeneratePassword.html", inputData)
}