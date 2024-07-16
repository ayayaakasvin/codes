package leetcode

func threeConsecutiveOdds(arr []int) bool {
	var counter int

	for i := 0; i < len(arr); i++ {
		switch temp := arr[i]; {
		case temp % 2 == 0 :
			counter = 0;
		case temp % 2 == 1 :
			counter++;
		}

		if counter == 3 {
			return true
		}
	}

	return false
}