package leetcode

import (
	"math"
	"strconv"
)

func convertToBase7(num int) string {
	var (
		abs_num int = int(math.Abs(float64(num)));
		base_7_number int;
		is_negative bool = abs_num != num;
		answer string;
	)

	for i := 0; abs_num != 0; i++{
		base_7_number += (abs_num % 7) * int(math.Pow(float64(10), float64(i)));
		abs_num /= 7;
	}

	if is_negative {
		answer = "-" + 	strconv.Itoa(base_7_number);
	} else {
		answer = strconv.Itoa(base_7_number);
	}

	return answer
}