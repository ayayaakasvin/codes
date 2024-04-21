package kata

func createPartAndAppend (timeToIterator int, sliceToAppend *[][]int) {
	var partOfPyramid []int
	
	for i := 0; i <= timeToIterator; i++ {
		partOfPyramid = append(partOfPyramid, 1)
	}

	(*sliceToAppend) = append((*sliceToAppend), partOfPyramid)
}

func Pyramid(n int) [][]int {
	var result [][]int = [][]int{}

	for i := 0; i < n; i++ {
		createPartAndAppend(i, &result)
	}

	return result
}