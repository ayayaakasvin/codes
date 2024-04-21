package kata

func SortMyString(s string) string {
	var oddString, evenString string

	for i := 0; i < len([]rune(s)); i++ {
		if i%2 == 0 {
			evenString += string(s[i])
		} else {
			oddString += string(s[i])
		}
	}

	return evenString + " " + oddString
}
