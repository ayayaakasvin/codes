package leetcode

import "fmt"

func SummaryRanges(nums []int) []string {
	if len(nums) == 0 {
		return []string{}
	}

	var result []string = []string{}
	var lengthOfNums int = len(nums)
	var tempRange [2]int = [2]int{nums[0], nums[0]}

	for i := 1; i < lengthOfNums; i++ {
		if nums[i] - nums[i - 1] == 1 {
			tempRange[1] = nums[i]
		} else {
			if tempRange[1] != tempRange[0] {
				result = append(result, fmt.Sprintf("%d->%d", tempRange[0], tempRange[1]))
			} else {
				result = append(result, fmt.Sprintf("%d", tempRange[0]))
			}

			tempRange = [2]int{nums[i], nums[i]}
		}
	}

	if tempRange[1] != tempRange[0] {
		result = append(result, fmt.Sprintf("%d->%d", tempRange[0], tempRange[1]))
	} else {
		result = append(result, fmt.Sprintf("%d", tempRange[0]))
	}

	return result
}