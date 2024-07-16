package leetcode

func abs(n int) int {
	mask := n >> 31
	return (n ^ mask) - mask
}

func SortedSquares(nums []int) []int {
	var indexForResult int = len(nums) - 1
	var result []int = make([]int, indexForResult + 1)


    for start, end := 0, indexForResult; start <= end;  {
		if abs(nums[start]) < abs(nums[end]) {
			result[indexForResult] = nums[end] * nums[end]
			end--
			indexForResult--
		} else {
			result[indexForResult] = nums[start] * nums[start]
			start++
			indexForResult--
		}
	}

	return result
}