package leetcode

func sortPeople(names []string, heights []int) []string {
    var lengthOfNameSlice int = len(names)

	for i := 0; i < lengthOfNameSlice;  {
		for j := i + 1; j < lengthOfNameSlice; {
			if heights[i] < heights[j] {
				heights[i], heights[j] = heights[j], heights[i]
				names[i], names[j] = names[j], names[i]
			} else
		}
	}

	return names
}