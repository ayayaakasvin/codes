package kata

import (
	"slices"
	"strconv"
)

func latestHours (arrayOfNumeros *[]int) []int {
	var tenHour, unitHour int
	var hourAvailableSet = [2]int{2, 1}

	for _, value := range hourAvailableSet {
		var pos int = slices.Index(*arrayOfNumeros, value) 
		if  pos != -1 {
			tenHour = value
			*arrayOfNumeros = append((*arrayOfNumeros)[:pos], (*arrayOfNumeros)[pos + 1:]...)
			break
		}
	}

	for i := 9; i >= 0; i-- {
		var pos int = slices.Index(*arrayOfNumeros, i)
		if pos != -1 {
			unitHour  = i
			*arrayOfNumeros = append((*arrayOfNumeros)[:pos], (*arrayOfNumeros)[pos + 1:]...)
			break
		}
	}

	return []int{tenHour, unitHour}
}

func latestMinutes (arrayOfNumeros *[]int) []int {
	var tenMinute, unitMinute int
	for i := 6; i >= 0; i-- {
		var pos int = slices.Index(*arrayOfNumeros, i)
		if pos != -1 {
			tenMinute  = i
			*arrayOfNumeros = append((*arrayOfNumeros)[:pos], (*arrayOfNumeros)[pos + 1:]...)
			break
		}
	}

	unitMinute = (*arrayOfNumeros)[0]

	return []int{tenMinute, unitMinute}
}

func LatestClock(a int, b int, c int, d int) string {
	var numberSet []int = []int{a, b, c, d}
	var sortedArray []int
	var result string

	sortedArray = append(sortedArray, latestHours(&numberSet)...)
	sortedArray = append(sortedArray, latestMinutes(&numberSet)...)

	for _, v := range sortedArray {
		result += strconv.FormatInt(int64(v), 10)
	}

	return result
}