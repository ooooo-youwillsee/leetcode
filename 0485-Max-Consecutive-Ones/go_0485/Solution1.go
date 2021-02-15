package main

import (
	"fmt"
)

func findMaxConsecutiveOnes(nums []int) int {
	nums = append(nums, 0)
	count := 0
	ans := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] == 0 {
			ans = max(ans, count)
			count = 0
		} else {
			count++
		}
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
	cnt := findMaxConsecutiveOnes([]int{1, 0, 1, 1, 0, 1})
	fmt.Println(cnt)
}
