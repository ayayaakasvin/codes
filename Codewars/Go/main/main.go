package main

import (
	"example/hello/kata"
	"fmt"
)

func main() {
	fmt.Println(kata.Strong(5), "F")
	fmt.Println(kata.Strong(8), "F")
	fmt.Println(kata.Strong(145), "T")
	fmt.Println(kata.Strong(7), "F")
	fmt.Println(kata.Strong(0), "F")
}