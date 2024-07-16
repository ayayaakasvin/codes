package leetcode

func containsDuplicate(nums []int) bool {
    var mapOfAppereance map[int]int = map[int]int{}
	
	for _, number := range nums {
		mapOfAppereance[number]++
		if mapOfAppereance[number] > 1 {
			return true
		}
	}

	return false
}