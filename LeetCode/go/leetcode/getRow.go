package leetcode

func factorial(numero int) int {
	if numero == 0 {
		return 1
	}

	return numero * factorial(numero-1)
}

func GetRow(rowIndex int) []int {
	var result []int = []int{}

	var factorialOfRowIndex int = factorial(rowIndex)

	for i := 0; i <= rowIndex; i++ {
		var numero int
		var factorialOfIndex, factorialOfSubstruction int = factorial(i), factorial(rowIndex - i)
		numero = (factorialOfRowIndex) / (factorialOfIndex * factorialOfSubstruction)

		result = append(result, numero)
	}

	return result
}

func generate(numRows int) []int {
	var result [][]int = [][]int{{1}}

	for i := 1; i <= numRows; i++ {
		var temp []int = []int{1}

		for j := 1; j <= i-1; j++ {
			temp = append(temp, result[i-1][j-1]+result[i-1][j])
		}

		temp = append(temp, 1)
		result = append(result, temp)
	}

	return result[len(result)-1]
}
