package leetcode

import "fmt"

func IsPerfectSquare(num int) bool {
	var left, right int = 1, num / 2

	for left <= right {
		var numero int = (right + left) / 2
		fmt.Println(numero)
		var squareOfNumero = numero * numero
		if squareOfNumero == num {
			return true
		} else {
			if squareOfNumero > num {
				right = numero - 1
			} else {
				left = numero + 1
			}
		}
	}

	return false
}