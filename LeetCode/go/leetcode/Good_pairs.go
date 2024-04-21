package leetcode

func numIdenticalPairs(nums []int) int {
	var counter_of_Pairs int

	for i := 0; i < len(nums) - 1; i++ {
		for j := i + 1; j < len(nums); j++ {
			if	nums[i] == nums[j] {
				counter_of_Pairs++
			}
		}
	}

	return counter_of_Pairs;
}
