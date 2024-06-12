package prop
	
import (
	"fmt"
)

type Square struct {
	Length int
	Top *Square
	Bottom *Square
	Left *Square
	Right *Square
}

func (s Square) DrawTheSquare () {
	var drawing string = stringMultiplicationHorizontal(s.Length, false) +
			stringMultiplicationVertical(s.Length) +
			stringMultiplicationHorizontal(s.Length, true);

	fmt.Println(drawing)
}

type Triangle struct {
	//pass
}