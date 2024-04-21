package kata

import (
	"strconv"
	"strings"
)

func isPowerMoreThan10 (n2 string) int {
	if len(n2) > 2 {
		var strPower string = n2[len([]rune(n2)) - 2 :]
		power, _ := strconv.ParseInt(strPower, 10, 32)
		return int(power)
	}

	power, _ := strconv.ParseInt(n2, 10, 32)
	return int(power)
}

func LastDigit(n1, n2 string) int {
	if n2 == "0" {
		return 1
	}

	var (
		mapOfNumeros map[string][]int = map[string][]int{
			"2" : {2, 4, 8, 6},
			"3" : {3, 9, 7, 1},
			"4" : {4, 6},
			"7" : {7, 9, 3, 1},
			"8" : {8, 4, 2, 6},
			"9" : {9, 1},
		}
		nonChangableNumeros string = "0156"
		targetDigit = string(n1[len([]rune(n1)) - 1])
	)

	if strings.Contains(nonChangableNumeros, targetDigit) {
		var result, err = strconv.ParseInt(targetDigit, 10, 32)
		if err != nil {
			return 0
		}

		return int(result)
	}

	var powerOfTargetDigit int = isPowerMoreThan10(n2)
	var index int = int(powerOfTargetDigit) % len(mapOfNumeros[targetDigit])
	if index == 0 {
		index = len(mapOfNumeros[targetDigit]) - 1
	} else {
		index--
	}

	var result int = mapOfNumeros[targetDigit][index]

	return result
}