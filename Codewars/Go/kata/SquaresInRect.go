package kata

func swapTheValue(firstNumero *int, secondNumero *int) {
	if *firstNumero < *secondNumero {
		*firstNumero, *secondNumero = *secondNumero, *firstNumero
	}
}

func appendingToTheArray(elementToAppend int, timesToAppend int, arrayToAppend *[]int) {
	for i := 0; i < timesToAppend; i++ {
		*arrayToAppend = append(*arrayToAppend, elementToAppend)
	}
}

func gettingTheSquares(lng *int, wdth *int) (int, int) {
	var (
		square      int = *wdth
		iterateTime int = *lng / *wdth
	)

	*lng, *wdth = *wdth, *lng % *wdth
	return square, iterateTime
}

func SquaresInRect(lng int, wdth int) []int {
	if lng == wdth {
		return nil
	}

	swapTheValue(&lng, &wdth)

	var (
		result []int
	)

	for lng > 0 && wdth > 0 {
		square, i := gettingTheSquares(&lng, &wdth)
		if square == 0 || i == 0 {
			break
		}
		appendingToTheArray(square, i, &result)
	}

	return result
}
