package kata

import (
	"strings"
	"unicode"
)

func splitIntoParts(Sheet string) (mapToReturn map[string]string) {
	var sliceOfResultsSplittedBy []string = strings.Split(Sheet, ",")
	var commandNameTemp, scoreTemp string

	for _, value := range sliceOfResultsSplittedBy {
		var sliceOfWords []string = strings.Split(value, " ")
		for i := 0; i < len(sliceOfWords) - 1; i++ {
			if unicode.IsLetter(rune(sliceOfWords[i][0])) {
				commandNameTemp += sliceOfWords[i] + " "
				scoreTemp = ""
			} else {
				scoreTemp += sliceOfWords[i]
				commandNameTemp = ""
			}
		}
	}

	return
}

func NbaCup(resultSheet, toFind string) string {
	return ""
}
