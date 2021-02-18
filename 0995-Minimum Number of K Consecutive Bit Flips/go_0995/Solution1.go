/**
* @Author: ooooo
* @Date: 2021/2/18 08:54
 */

package main

import (
	"fmt"
)

// 模拟
func minKBitFlips(A []int, K int) int {
	n := len(A)
	ans := 0
	for i := 0; i < n; i++ {
		if A[i] == 1 {
			continue
		}
		if i+K-1 >= n {
			return -1
		}
		ans++
		for j := 0; j < K; j++ {
			A[i+j] ^= 1
		}
	}
	return ans
}

func main() {
	fmt.Println(minKBitFlips([]int{0, 1, 0}, 1))                // 2
	fmt.Println(minKBitFlips([]int{1, 1, 0}, 2))                // -1
	fmt.Println(minKBitFlips([]int{0, 0, 0, 1, 0, 1, 1, 0}, 3)) // 3

}
