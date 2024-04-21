package kata

func Facrotial(n int) int {
	if n == 0 {
		return 1
	}

	return n * Facrotial(n-1)
}

func Strong(n int) string {
	var isStrong bool = false
	var ValueToCompare int
	var temp int = n

	for ; temp > 0 ; {
		var digit int = temp % 10
		ValueToCompare += Facrotial(digit)
		temp /= 10
	}

	isStrong = ValueToCompare == n

	if isStrong {
		return "STRONG!!!!"
	} else {
		return "Not Strong !!"
	}
}