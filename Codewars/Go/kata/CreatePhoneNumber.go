package kata

import "strconv"

func returnStringVersion(numbers []uint) string {
	var numeroString string
	for i := 0; i < len(numbers); i++ {
		numeroString += strconv.FormatInt(int64(numbers[i]), 10)
	}

	return numeroString
}

func CreatePhoneNumber(numbers [10]uint) string {
	var result string

	result = "(" + returnStringVersion(numbers[:3]) + ") " + returnStringVersion(numbers[3:6]) + "-" + returnStringVersion(numbers[6:10])

	return result
}