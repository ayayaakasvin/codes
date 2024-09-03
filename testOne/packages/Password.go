package packages

import (
    "golang.org/x/crypto/bcrypt"
)

// HashPassword hashes the given password using bcrypt and returns the hashed password as a string.
func HashPassword(password string) (string, error) {
    hashedPassword, err := bcrypt.GenerateFromPassword([]byte(password), bcrypt.DefaultCost)
    if err != nil {
        return "", err
    }

    return string(hashedPassword), nil
}

func ComparePassword (password, hash string) (bool) {
    err := bcrypt.CompareHashAndPassword([]byte(hash), []byte(password))
    return err == nil
}