package main

import (
	"fmt"
	"time"
	"github.com/ayayaakasvin/randompass/password"
)

func main() {
	// Start the timer
	start := time.Now()

	// Generate a random password and print it
	password := randompass.CreateRandomPassword(true, true, true, true, 69)
	fmt.Println(string(password.PasswordItself))

	// Loop to generate and print 50 random passwords
	for i := 0; i < 50; i++ {
		fmt.Println(string(randompass.CreateRandomPassword(true, true, true, true, 50).PasswordItself))
	}

	// Calculate the elapsed time
	elapsed := time.Since(start)
	fmt.Printf("Program executed in %s\n", elapsed)
}