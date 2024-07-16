package leetcode

func MaxProfit(prices []int) int {
    var (
		profit int
		minBetweenTwoPrices int = prices[0]
	)
	
	for _, price := range prices {
		if price < minBetweenTwoPrices {
			minBetweenTwoPrices = price
		} else {
			var tempProfit int = price - minBetweenTwoPrices

			if tempProfit > profit {
				profit = tempProfit
			}
		}
	}

	return profit
}