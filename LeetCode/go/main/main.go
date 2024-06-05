package main

import (
	"fmt"
	"lol/leetcode"
)

func main() {
	fmt.Println(leetcode.IsPalindromeString("hello"))
	fmt.Println(leetcode.IsPalindromeString("hel 1 leh"))
	fmt.Println(leetcode.IsPalindromeString("A man, a plan, a canal: Panama"))
	fmt.Println(leetcode.IsPalindromeString("race a car"))
	fmt.Println(leetcode.IsPalindromeString(" "))
	fmt.Println(leetcode.IsPalindromeString(""))
}