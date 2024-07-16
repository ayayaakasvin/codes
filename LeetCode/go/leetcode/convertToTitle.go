package leetcode

func getTheBase_26(numero *int) (byte) {
	var resultInt int = ((*numero) - 1) % 26
	*numero = (*numero - 1) / 26

	return byte(resultInt + 'A')
}

func ConvertToTitle(columnNumber int) string {
    var result string

	for ; columnNumber != 0 ; {
		result = string(getTheBase_26(&columnNumber)) + result
	}

	return result
}