package kata

import "math"

func FindNextSquare(sq int64) int64 {
	var root int64 = int64(math.Sqrt(float64(sq)))
	if root * root != int64(sq) {
		return -1
	}

	return int64(math.Pow(float64(root + 1), float64(2)))
}