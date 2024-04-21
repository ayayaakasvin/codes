package kata

import "strings"

const vowelLetters string = "aeuioAEUIO"

func Disemvowel(comment string) string {
	var letters = latinLetter{
		vowels: vowelLetters,
	}

	var result string
	for i := 0; i < len([]rune(comment)); i++ {
		if !strings.Contains(letters.vowels, string(comment[i])) {
			result += string(comment[i])
		}
	}
	
	return result
}