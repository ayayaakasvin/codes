package prop

func stringMultiplicationHorizontal (length int, isBottom bool) string {
	var buffer string

	for i := 0; i < length; i++ {
		buffer += "* "
	}

	if !(isBottom) {
		buffer += "\n"	
	}

	return buffer
}

func stringMultiplicationVertical (length int) string {
	var buffer, temp string
	temp = "*"

	for i := 0; i < length - 2; i++ {
		temp += "  "
	}
	temp += " *"

	for i := 0; i < length - 2; i++ {
		buffer += temp + "\n"
	}

	return buffer
}