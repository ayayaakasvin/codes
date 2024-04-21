package leetcode

import "sort"

func isNegativeOnesMoreThan2 (nums []int) (bool) {
	var isNegativeEven int
	for i := 0; i < len(nums); i++ {
		if (nums)[i] < 0 {
			isNegativeEven++
		}
	}

	return isNegativeEven >= 2
}

func comparingResults (nums []int) int {
	var first, second int = productOfSlice([]int{nums[0], nums[1], nums[len(nums)-1]}),  productOfSlice(nums[len(nums)-3:])
	if first > second {
		return first
	}

	return second
}

func productOfSlice (nums []int) int {
	var result int = 1
	for i := 0; i < len(nums); i++ {
		result *= nums[i]
	}

	return result
}

func MaximumProduct(nums []int) int {
	if len(nums) < 4 {
		return productOfSlice(nums)
	}

	sort.Ints(nums)

	if isNegativeOnesMoreThan2(nums) {
		return comparingResults(nums)
	}

	return productOfSlice(nums[len(nums) - 3:])
}