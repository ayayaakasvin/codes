package leetcode

func IsPowerOfTwo(n int) bool {
	var toCompare int = 1
    for n > toCompare {
		toCompare <<= 1
	}

	return n == toCompare
}