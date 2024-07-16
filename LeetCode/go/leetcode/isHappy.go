package leetcode

func getTheSumOfSquares(n int) int {
	var result int
	for ; n > 0 ; {
		var square int = (n % 10) * (n % 10)
		result += square
		n /= 10
	}

	return result
}

func isHappy(n int) bool {
	var AppereanceOfSums map[int]bool = map[int]bool{}
	for n != 1 {
		n = getTheSumOfSquares(n)
		if AppereanceOfSums[n] {
			return false
		} else {
			AppereanceOfSums[n] = true
		}
	}

	return true
}