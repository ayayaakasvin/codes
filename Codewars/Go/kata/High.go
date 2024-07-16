package kata

import "strings"

type Word struct {
	value string
	score int
}

func NewWord (input string) Word {
	scoreOfWord := 0
	for _, character := range input {
		scoreOfWord += int(character - 'a' + 1)
	}
	
	return Word{value: input, score: scoreOfWord}
}

func High(s string) string {
	var sliceOfWords []string = strings.Split(s, " ")
	var result Word = NewWord(sliceOfWords[0])

	for _, word := range sliceOfWords {
		var temp Word = NewWord(word)

		if temp.score > result.score {
			result = temp
		}
	}

	return result.value
}