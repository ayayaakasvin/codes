package leetcode

func IsPowerOfThree(n int) bool {
	var base int = 1
	if n < 1 && n > 0 {

		for base > n{
			base /= 3
		}

	} else {

		for base < n {
			base *= 3
		}
		 
	}

	return base == n
}