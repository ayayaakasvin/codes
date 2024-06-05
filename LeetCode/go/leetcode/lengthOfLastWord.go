package leetcode

import "unicode"

func trunkNonLetters(text *string) {
	var lengthOfText int = len([]rune((*text))) - 1

	for lengthOfText >= 0 {
		if !unicode.IsLetter(rune((*text)[lengthOfText])) {
			*text = (*text)[:lengthOfText]
			lengthOfText--
		} else {
			break
		}
	}
}

func LengthOfLastWord(s string) int {
	var lengthOfLastWord int
	trunkNonLetters(&s)
	var lengthOfText int = len([]rune(s)) - 1

	for i := lengthOfText; i >= 0; i-- {
		if !unicode.IsLetter(rune(s[i]))  {
			return lengthOfLastWord
		}

		lengthOfLastWord++
	}

	return lengthOfLastWord
}
