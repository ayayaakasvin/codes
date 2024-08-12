package leetcode

func isPowerOfFour(n int) bool {
	var toCompare int = 1
    for n > toCompare {
		toCompare <<= 2
	}

	return n == toCompare
}