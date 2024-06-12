package leetcode

import (
	"math"
)

func findDifference(firstLetter, secondLetter byte) int {
	return int(math.Abs(float64((int(firstLetter)) - (int(secondLetter)))))
}


func ScoreOfString(s string) int {
	var result int

	for i := 0; i < len([]rune(s)) - 1; i++ {
		var diff int = findDifference(s[i], s[i + 1])
		result += diff
	}

	return result
}