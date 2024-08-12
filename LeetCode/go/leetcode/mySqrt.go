package leetcode

func MySqrt(x int) int {
	if x == 1 {
		return 1
	}

	var left, right int = 1, x / 2

	for left <= right {
		var numero int = (right + left) / 2
		var squareOfNumero = numero * numero
		if squareOfNumero == x {
			return numero
		} else {
			if squareOfNumero > x {
				right = numero - 1
			} else {
				left = numero + 1
			}
		}
	}

    return right
}