package leetcode

func ContainsNearbyDuplicate(nums []int, k int) bool {
	var mapOfIndex map[int]int = make(map[int]int)

	for i := 0; i < len(nums); i++{
		index, ok := mapOfIndex[nums[i]]

		if ok && (i - index) <= k  {
			return true
		}

		mapOfIndex[nums[i]] = i
	}

	return false
}