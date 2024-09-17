package packages

import "fmt"

const (
	WebSiteNaming string = "Generate Random Password"
)

type PassToHTMLForTypeCheck struct {
	Upper bool
	Lower bool
	Digit bool
	Special bool
}

func TypeCheckPassConstructor (upper, lower, digit, special bool) *PassToHTMLForTypeCheck {
	return &PassToHTMLForTypeCheck{
		Upper: upper,
		Lower: lower,
		Digit: digit,
		Special: special,
	}
}

func PrintHello () {
	fmt.Println("Hello")
}