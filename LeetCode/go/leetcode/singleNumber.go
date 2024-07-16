package leetcode

func mapOfAppereance (nums []int) map[int]int {
	var mapOfAppereance map[int]int = map[int]int{}
	
	for _, value := range nums {
		mapOfAppereance[value]++
	}

	return mapOfAppereance
}

func singleNumber(nums []int) int {
    var appereanceOfInts map[int]int = mapOfAppereance(nums)

	for key, value := range appereanceOfInts {
		if value == 1 {
			return key
		}
	}

	return -1
}