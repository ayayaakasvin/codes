package kata

import "strconv"

func Serie(i int) float64 {
	var (
		numerator float64 = 1.0
		divider   int = 1 + 3 * (i)
		result    float64 = (numerator / float64(divider))
	)

	return result
}

func SeriesSum(n int) string {
	var result float64

	for i := 0; i < n; i++ {
		result += Serie(i)
	}

	var answer string = strconv.FormatFloat(result, 'f', 2, 64)

	return answer
}
