package leetcode

func findMaxElem (row []int) (int, []int) {
	if len(row) == 1 {
		return row[0], nil
	}

	var maxElem, maxIndex, lengthOfRow int = row[0], 0, len(row)

	for i, j := 0, lengthOfRow - 1; i <= j; {
		if row[i] > maxElem {
			maxElem = row[i]
			maxIndex = i
		}
		
		if row[j] > maxElem {
			maxElem = row[j]
			maxIndex = j
		}

		i++;j--;
	}

	copy(row[maxIndex:], row[maxIndex + 1:])
	row = row[:len(row) - 1]

	return maxElem, row
}

func deleteGreatestValue(grid [][]int) int {
    var (
		result int
	)

	for len(grid) > 0 && len(grid[0]) > 0  {
		var maxElementsSLice []int

		for i := 0; i < len(grid); i++ {
			var value int
			value, grid[i] = findMaxElem(grid[i])
			maxElementsSLice = append(maxElementsSLice, value)
		}

		valueToAdd, _ := findMaxElem(maxElementsSLice)
		result += valueToAdd
	}

	return result
}