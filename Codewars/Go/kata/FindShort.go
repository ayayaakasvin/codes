package kata

import (
	"strings"
)

func findMin(arrayOfWords []string) (result int) {
	result = len([]rune(arrayOfWords[0]))

	for _, value := range arrayOfWords {
		var lengthOfWord int = len([]rune(value))
		if result > lengthOfWord {
			result = lengthOfWord
		}
	}

	return
}

func FindShort(s string) int {
	var sliceOfWords []string = strings.Split(s, " ")

	return findMin(sliceOfWords)
}