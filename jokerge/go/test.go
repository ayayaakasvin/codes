package main

import (
	// "fmt"
	"os"
	"os/exec"
	"proj/dbplus"
	"proj/password"
	"runtime"
	// "time"
)

func clearTerminal() {
	var clearCmd *exec.Cmd
	if runtime.GOOS == "windows" {
		clearCmd = exec.Command("cmd", "/c", "cls")
	} else {
		clearCmd = exec.Command("clear")
	}
	clearCmd.Stdout = os.Stdout

	clearCmd.Run()
}

func main () {
	clearTerminal()

	var password password.PasswordStruct = password.PasswordCreate()
	var database dbplus.DataBaseProps = dbplus.DataBaseProps{
		Database: "golangEx",
		Host: "localhost",
		Port: "6969",
		User: "postgres",
		Password: "1947",
	}

	database.ConnectToDB()
	defer database.CloseTheDB()

	database.INSERT_INTO(string(password.PasswordItself))

	// for i := 5; i > 0 ; i-- {
	// 	fmt.Printf("Terminal will be cleared out after: %v second\n", i)
	// 	time.Sleep(1 * time.Second)
	// }
	// clearTerminal()

	// main()
}