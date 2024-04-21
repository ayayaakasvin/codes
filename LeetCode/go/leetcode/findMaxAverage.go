package leetcode

func compare(a, b float64) float64 {
	if a > b {
		return float64(a)
	}

	return float64(b)
}

func FindMaxAverage(nums []int, k int) float64 {
	var sum float64

	for i := 0; i < len(nums); i++ {
		sum += float64(nums[i]) / float64(k)
	}

	var current float64 = sum

	for i, j := 0, k; j < len(nums); {
		current = (current + float64(nums[i]) - float64(nums[j])) / float64(k)
		sum = compare(sum, current)
		i++
		j++
	}

	return sum
}
