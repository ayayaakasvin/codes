package leetcode

func getTheMapOfAppereance (nums []int) map[int]bool {
	var mapOfAppereance map[int]bool = map[int]bool{}
	
	for _, value := range nums {
		mapOfAppereance[value] = true
	}

	return mapOfAppereance
}

func missingNumber(nums []int) int {
    var mapOfAppereance map[int]bool = getTheMapOfAppereance(nums)
	var result int
	for i := 0; i <= len(nums); i++ {
		if !mapOfAppereance[i] {
			result = i
			break
		}
	}

	return result
}