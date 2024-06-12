package leetcode

func Generate(numRows int) [][]int {
	var result [][]int = [][]int{{1}}

	for i := 1; i < numRows; i++ {
		var temp []int = []int{1}

		for j := 1; j <= i-1; j++ {
			temp = append(temp, result[i-1][j-1]+result[i-1][j])
		}

		temp = append(temp, 1)
		result = append(result, temp)
	}

	return result
}
