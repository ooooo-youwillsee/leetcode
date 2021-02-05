/**
* @Author: ooooo
* @Date: 2021/2/5 21:16
 */

package main

import (
	"fmt"
)

func equalSubstring(s string, t string, maxCost int) int {
	l, r := 0, 0
	ans := 0
	for r < len(s) && l < len(s) {
		if abs(int(s[r])-int(t[r])) <= maxCost {
			maxCost -= abs(int(s[r]) - int(t[r]))
			r++
			ans = max(ans, r-l)
		} else {
			maxCost += abs(int(s[l]) - int(t[l]))
			l++
		}
	}
	return ans
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	s := "abcd"
	t := "bcdf"
	maxCost := 3
	fmt.Println(equalSubstring(s, t, maxCost))
}
