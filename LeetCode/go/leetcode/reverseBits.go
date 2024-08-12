package leetcode

func ReverseBits(num uint32) uint32 {
	var result uint32
	var lengthOfNum int = 31

    for num != 0 {
		result |= (num & 1) << lengthOfNum
		lengthOfNum--
		num >>= 1
	}

	return result
}