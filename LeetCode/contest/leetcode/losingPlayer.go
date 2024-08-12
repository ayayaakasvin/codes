package leetcode

func LosingPlayer(x int, y int) string {
    var winner string = "Bob"

	for x >= 1 && y >= 4 {
		if winner == "Alice" {
			winner = "Bob"
		} else {
			winner = "Alice"
		}
		x--
		y -= 4
	}

	return winner
}