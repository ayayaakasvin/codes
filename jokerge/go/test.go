package main

import (
	// "time"
	"Drawer/prop"
)

func main () {
	var sq prop.Square = prop.Square{Length: 15}
	// var ticker time.Ticker

	sq.DrawTheSquare()
}