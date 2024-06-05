package leetcode

func xorAllElems (arr []int) (result int) {
	result = arr[0]
	for i := 1; i < len(arr); i++ {
		result ^= arr[i]
	}

	return
}

func CountTriplets(arr []int) int {
    var (
		count int
	)

	for i := 0; i < len(arr); i++ {

		for j := i + 1; j < len(arr); j++ {

			var (
				firstPart int
				secondPart int
			)

			firstPart = xorAllElems(arr[i:j])
			secondPart = xorAllElems(arr[j:])

			if firstPart == secondPart {
				count++
			}
		}
	}

	return count
}