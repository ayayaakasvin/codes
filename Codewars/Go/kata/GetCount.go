package kata

import (
	"strings"
	"unicode"
)

type latinLetter struct {
	vowels string
}

func (l latinLetter) isVowel (char rune) (res bool) {
	res = unicode.IsLetter(char) && strings.Contains(l.vowels, string(char))
	return
}

func GetCount(str string) (count int) {
	var letters = latinLetter{
		vowels: "aeuio",
	}

	for _, v := range str {
		if letters.isVowel(v) {
			count++
		}
	}

	return
}