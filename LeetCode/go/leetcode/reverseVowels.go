package leetcode

func ReverseVowels(s string) string {
	if s == "" || s == " " {
		return s
	}

	var vowels map[byte]bool = map[byte]bool{
		'a' : true, 'A' : true,
		'e' : true, 'E' : true,
		'u' : true, 'U' : true,
		'i' : true, 'I' : true,
		'o' : true, 'O' : true,
	}

	var sliceOfChars []byte = []byte(s) 

    for i, j := 0, len(sliceOfChars) - 1; i < j; {
		if !vowels[sliceOfChars[i]] {
			i++
		} else if !vowels[sliceOfChars[j]] {
			j--	
		}
		
		if vowels[sliceOfChars[i]] && vowels[sliceOfChars[j]] {
				var temp byte = sliceOfChars[i]
				sliceOfChars[i] = sliceOfChars[j]
				sliceOfChars[j] = temp
				i++; j--
			}
	}
	
	return string(sliceOfChars)
}