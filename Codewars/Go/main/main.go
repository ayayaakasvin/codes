package main

import (
	"codewars/kata"
	"fmt"
)

func main() {
	fmt.Println(kata.CreatePhoneNumber([10]uint{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}), "(123) 456-7890")
	fmt.Println(kata.CreatePhoneNumber([10]uint{7, 7, 1, 1, 7, 8, 1, 5, 5, 1}), "(771) 178-1551")
}
