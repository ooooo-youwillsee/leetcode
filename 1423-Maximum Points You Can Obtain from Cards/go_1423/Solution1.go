/**
* @Author: ooooo
* @Date: 2021/2/6 18:18
 */

package go_1423

func maxScore(cardPoints []int, k int) int {
	minSum, n := 0, len(cardPoints)
	for i := 0; i < n-k; i++ {
		minSum += cardPoints[i]
	}
	ans := minSum
	for i := 1; i <= k; i++ {
		minSum -= cardPoints[i-1]
		minSum += cardPoints[i+n-k-1]
		ans = min(ans, minSum)
	}
	totalSum := 0
	for _, v := range cardPoints {
		totalSum += v
	}
	return totalSum - ans
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
