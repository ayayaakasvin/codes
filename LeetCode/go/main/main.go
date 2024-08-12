package main

import (
	"fmt"
	"lol/leetcode"
)

func main() {
	fmt.Println(leetcode.AddStrings("11", "123"), 134)
	fmt.Println(leetcode.AddStrings("456", "77"), 533)
	fmt.Println(leetcode.AddStrings("0", "0"), 0)
}