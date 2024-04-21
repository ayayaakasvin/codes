package kata

func minElementFromThree (a, b, c int) int {
	if a <= b && a <= c {
		return a
	} else if b <= a && b <= c {
		return b
	}
	
	return c
}

func SmallestIntegerFinder(numbers []int) int {
	var minElem int = numbers[0]
 	for i, j := 0, len(numbers) - 1; i <= j;{
		minElem = minElementFromThree(numbers[i], numbers[j], minElem)
		i++;j--;
  	}

	return minElem
}