package leetcode

func AddBinary(a string, b string) string {
    var (
		lengthOfA int = len(a) - 1
		lengthOfB int = len(b) - 1
		nextBitAdd int
		binary string
	)

	for lengthOfA >= 0 || lengthOfB >= 0 || nextBitAdd != 0 {
		if lengthOfA > -1 {
			nextBitAdd += int(a[lengthOfA] - '0')
			lengthOfA--
		}

		if lengthOfB > -1 {
			nextBitAdd += int(b[lengthOfB] - '0')
			lengthOfB--
		}

		binary += string(nextBitAdd % 2 + '0')
		nextBitAdd = nextBitAdd / 2
	}

	var result string
	for _, v := range binary {
		result = string(v) + result
	}

	return result
}