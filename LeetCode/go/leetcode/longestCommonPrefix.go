package leetcode

func lengthOfWordMin(strs []string) (length int) {
	length = (len([]rune(strs[0])))
	for _, value := range strs {
		if length > (len([]rune(value))) {
			length = (len([]rune(value)))
		}
	}

	return
}

func LongestCommonPrefix(strs []string) string {
	var (
		prefix          string = ""
		LengthOfMinWord int    = lengthOfWordMin(strs)
	)

	for i := 0; i < LengthOfMinWord; i++ {
		for j := 0; j < len(strs)-1; j++ {
			if strs[j][i] != strs[j+1][i] {
				return prefix
			}
		}
		
		prefix += string(strs[0][i])
	}

	return prefix
}
