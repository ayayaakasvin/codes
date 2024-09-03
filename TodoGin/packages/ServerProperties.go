package packages

import (
	"fmt"
	"regexp"
	"strconv"
	"strings"

	"golang.org/x/crypto/bcrypt"
)

const (
    DigitsRegexp = "[0-9]"
    LatinRegexp = `[a-zA-Z]`
    MinLength = 8
    MaxLength = 64
    InternalErrorString = "Internal error occurred during validation"
    LatinError = "Password should contain at least one latin letter"
    DigitError = "Password should contain at least one digit"
    SpaceError = "Password should not contain space"
    PasswordNotMatch = "Passwords do not match"
    UserAlreadyExistError = "User already exists"
    UsernameContainsSpace = "Username should not contain space"
    ErrorPasswordHTML = "PasswordError"
    ErrorUsernameHTML = "UserExistError"
    ErrorLoginHTML = "LoginError"
    LoginError = "Incorrect username or password"
    Form = "Form"
    ConvertError = "StrToInt error"
    GetTaskError = "Task parsing error"
)

// HashPassword hashes the given password using bcrypt and returns the hashed password as a string.
func HashPassword(password string) (string, error) {
    hashedPassword, err := bcrypt.GenerateFromPassword([]byte(password), bcrypt.DefaultCost)
    if err != nil {
        return "", err
    }

    return string(hashedPassword), nil
}

// Compares password with hash from database
func ComparePassword (password, hash string) (bool) {
    err := bcrypt.CompareHashAndPassword([]byte(hash), []byte(password))
    return err == nil
}

// Checks if gained password valid, if it is unvalid return error
func IsValidPassword (pword string) (error) {
    passwordByted := []byte(pword)

    if len(passwordByted) < MinLength {
        return fmt.Errorf("Password length must be at least %d", MinLength)
    } else if len(passwordByted) > MaxLength {
        return fmt.Errorf("Password length must be at most %d", MaxLength)
    }

    if matched, err := regexp.Match(LatinRegexp, passwordByted); err != nil {
        return fmt.Errorf(InternalErrorString)
    } else if !matched {
        return fmt.Errorf(LatinError)
    }

    if digitValid, err := regexp.Match(DigitsRegexp, passwordByted); err != nil {
        return fmt.Errorf(InternalErrorString)
    } else if !digitValid {
        return fmt.Errorf(DigitError)
    }

    if ContainSpace(pword) {
        return fmt.Errorf(SpaceError)
    }

    return nil
}

// Checks if gained username valid, if it is unvalid return error
func IsValidUsername (uname string) (error) {
    if ContainSpace(uname) {
        return fmt.Errorf(UsernameContainsSpace)
    }

    return nil
}

// Returns true if string contains space(\s)
func ContainSpace (input string) bool {
    return strings.Contains(input, " ")
}

// Returns string with trimed beginning and end 
func TrimSpace (input string) string {
    return strings.TrimSpace(input)
}

func StrToInt (input string) (int) {
    result, err := strconv.Atoi(input)
    if err != nil {
        return -1
    }

    return result
}