package leetcode

import "math"

func TitleToNumber(columnTitle string) int {
    var result int
	var lengthOfTitle = len(columnTitle)

	for i := lengthOfTitle - 1; i >= 0; i-- {
		result += int(columnTitle[i] - 'A' + 1) * int(math.Pow(float64(26), float64(lengthOfTitle - i - 1)))
	}

	return result
}