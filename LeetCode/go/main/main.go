package main

import (
	"fmt"
	"lol/leetcode"
)

func main() {
	fmt.Println(leetcode.FindMaxAverage([]int{1, 12, -5, -6, 50, 3}, 4))
	fmt.Println(leetcode.FindMaxAverage([]int{5}, 1))
	fmt.Println(leetcode.FindMaxAverage([]int{1, 0, 1, 4, 2}, 4), "|", 1.7500)
}
