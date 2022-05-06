/**
* @Author: ooooo
* @Date: 2021/2/18 09:50
 */

package main

import (
	"fmt"
)

// 队列
func minKBitFlips(A []int, K int) int {
	n := len(A)
	ans := 0
	q := make([]int, 0, K)
	for i := 0; i < n; i++ {
		for len(q) > 0 && q[0] < i-K+1 {
			q = q[1:]
		}
		if (len(q)+A[i])%2 == 0 {
			if i+K-1 >= n {
				return -1
			}
			q = append(q, i)
			ans++
		}
	}
	return ans
}

func main() {
	fmt.Println(minKBitFlips([]int{0, 1, 0}, 1))                // 2
	fmt.Println(minKBitFlips([]int{1, 1, 0}, 2))                // -1
	fmt.Println(minKBitFlips([]int{0, 0, 0, 1, 0, 1, 1, 0}, 3)) // 3

}
