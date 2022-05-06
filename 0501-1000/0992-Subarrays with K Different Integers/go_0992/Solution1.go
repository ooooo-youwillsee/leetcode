package main

import (
	"fmt"
)

func subarraysWithKDistinct(A []int, K int) int {
	return atMostKDistinct(A, K) - atMostKDistinct(A, K-1)
}

func atMostKDistinct(A []int, K int) int {
	l, r := 0, 0
	ans := 0
	m := map[int]int{}
	count := 0
	for r < len(A) {
		if m[A[r]] == 0 {
			count++
		}
		m[A[r]]++
		r++

		for count > K {
			m[A[l]]--
			if m[A[l]] == 0 {
				count--
			}
			l++
		}

		// 以右端点来看
		ans += r - l
	}
	return ans
}

func main() {
	A := []int{1, 2, 1, 2, 3}
	K := 2
	fmt.Println(subarraysWithKDistinct(A, K))
}
