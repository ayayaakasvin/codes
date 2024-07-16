package leetcode

func checkDifference (first, second int) int {
	var result int = first - second

	if result < 0 {
		return result * -1
	}

	return result
}

func getSubarrayDiff (input []int) []int {
	var result []int

	for i := 0; i < len(input); i++ {
		for j := i; j < len(input); j++ {
			result = append(result, checkDifference(result[i], result[j]))
		}
	}

	return result
}

func checkIfLess (input []int, target int) (result int) {
	for _, v := range input {
		if v <= target {
			result++
		}
	}

	return
}

func longestSubarray(nums []int, limit int) int {
    for i := 0; i < len(nums); i++ {
		for j := i; j < len(nums); j++ {
			
		}
	}

	return 0
}