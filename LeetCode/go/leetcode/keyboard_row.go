package leetcode

type keyboard_keys struct {
	first_row string
	second_row string
	third_row string
}

func findWords(words []string) []string {
	var rows keyboard_keys
	rows.first_row = "qwertyuiop";
	rows.second_row = "asdfghjkl"
	rows.third_row = "zxcvbnm"

	return []string{"asd"} 	
}