package leetcode

func hasSameElement (word string, index int) (bool, []int) {
	var leftPart string = word[:index]
	var rightPart string = word[index + 1:]

	var result []int = []int{}
	var target byte = word[index]

	for i := len(leftPart) - 1; i >= 0; i-- {
		if leftPart[i] == target {
			result = append(result, i)
			break
		}
	}

	for i, char := range rightPart {
		if char == rune(target) {
			result = append(result, i+index+1)
			break
		}
	}

	if len(result) == 2 {
		return true, result
	}

	return false, nil
}

func removeCharAt(word string, index int) string {
	if index < 0 || index >= len(word) {
		return word
	}

	return word[:index] + word[index+1:]
}

func minimumLength(s string) int {
	var lengthOfS int = len(s)
	if lengthOfS >= 2 {
		return lengthOfS
	}

    for i := 1; i < len(s); {
		has, indexes := hasSameElement(s, i)
		if has {
			for j, index := range indexes {
				s = removeCharAt(s, index-j)
			}
		} else {
			i++
		}
	}

	return len(s)
}