package main

import (
	"fmt"
)

func maxTurbulenceSize(arr []int) int {
	if len(arr) <= 1 {
		return len(arr)
	}
	sz := len(arr)
	// dp[i][0] 表示 arr[i-1] > arr[i]，结尾的最长长度
	// dp[i][1] 表示 arr[i-1] < arr[i]，结尾的最长长度
	dp := make([][2]int, sz)
	dp[0][0] = 1
	dp[0][1] = 1
	ans := 1

	for i := 1; i < len(arr); i++ {
		if arr[i-1] > arr[i] {
			dp[i][0] = dp[i-1][1] + 1
			dp[i][1] = 1
		} else if arr[i-1] < arr[i] {
			dp[i][1] = dp[i-1][0] + 1
			dp[i][0] = 1
		} else {
			dp[i][1] = 1
			dp[i][0] = 1
		}
		ans = max(ans, max(dp[i][0], dp[i][1]))
	}
	return ans
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	arr := []int{9, 4, 2, 10, 7, 8, 8, 1, 9}
	// arr := []int{9, 9}
	fmt.Println(maxTurbulenceSize(arr))

}
