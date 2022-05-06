package main

func minDistance(word1 string, word2 string) int {
	len1, len2 := len(word1), len(word2)
	dp := make([][]int, len1+1)
	for i := 0; i < len(dp); i++ {
		dp[i] = make([]int, len2+1)
	}

	for i := 0; i < len1; i++ {
		dp[i+1][0] = dp[i][0] + 1
	}

	for i := 0; i < len2; i++ {
		dp[0][i+1] = dp[0][i] + 1
	}

	for i := 0; i < len1; i++ {
		for j := 0; j < len2; j++ {
			if word1[i] == word2[j] {
				dp[i+1][j+1] = dp[i][j]
			} else {
				dp[i+1][j+1] = min(min(dp[i][j]+1, dp[i][j+1]+1), dp[i+1][j]+1)
			}
		}
	}
	return dp[len1][len2]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {

}
