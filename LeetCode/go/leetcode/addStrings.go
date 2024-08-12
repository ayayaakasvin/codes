package leetcode

func AddStrings(num1 string, num2 string) string {
	var result string
    var indexFirst int = len(num1) - 1 
    var indexSecond int = len(num2) - 1
	var carry int
	
	for ; indexFirst >= 0 || indexSecond >= 0 || carry != 0 ; {
		if indexFirst > -1 {
			carry += int(num1[indexFirst] - '0')
			indexFirst--
		}

		if indexSecond > -1 {
			carry += int(num2[indexSecond] - '0')
			indexSecond--
		}

		result = string((carry % 10) + '0') + result
		carry /= 10
	}

	return result
}