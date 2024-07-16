package leetcode

func findJudge(n int, trust [][]int) int {
    var trusts, trusted map[int]int = map[int]int{}, map[int]int{}
	var result int = -1
	
	for i := 0; i < len(trust); i++ {
		trusts[trust[i][0]]++
		trusted[trust[i][1]]++
	}

	for i := 1; i <= n; i++ {
		if trusted[i] - trusts[i] == n - 1 {
			result = i
			break
		}
	}

	return result
}