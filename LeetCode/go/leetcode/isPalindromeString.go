package leetcode

import (
	"unicode"
	"fmt"
)

func checkPallindrom (inputString string) bool {
	for i, j := 0, len(inputString) - 1; i < j; i, j = i + 1, j - 1 {
		if inputString[i] != inputString[j] {
			return false
		}
	}

	return true
}

func IsPalindromeString(s string) bool {
	var stringWithoutNonAlphaNumeric []rune = make([]rune, 0, len([]rune(s)))

    for _, value := range s {
		if unicode.IsLetter(value) || unicode.IsDigit(value) {
			stringWithoutNonAlphaNumeric = append(stringWithoutNonAlphaNumeric, unicode.ToLower(value))
		}
	}

	fmt.Println(stringWithoutNonAlphaNumeric)
	return checkPallindrom(string(stringWithoutNonAlphaNumeric))
}