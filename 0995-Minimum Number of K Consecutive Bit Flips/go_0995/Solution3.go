/**
* @Author: ooooo
* @Date: 2021/2/18 09:50
 */

package main

import (
	"fmt"
)

//  差分数组
func minKBitFlips(A []int, K int) int {
	n := len(A)
	ans := 0
	revcnt := 0
	diff := make([]int, n+1)
	for i := 0; i < n; i++ {
		// 抵消第 i-K 个元素的贡献
		revcnt += diff[i]
		if (revcnt+A[i])%2 == 0 {
			if i+K-1 >= n {
				return -1
			}
			ans++
			revcnt++
			diff[i+K]--
		}
	}
	return ans
}

func main() {
	fmt.Println(minKBitFlips([]int{0, 1, 0}, 1))                // 2
	fmt.Println(minKBitFlips([]int{1, 1, 0}, 2))                // -1
	fmt.Println(minKBitFlips([]int{0, 0, 0, 1, 0, 1, 1, 0}, 3)) // 3

}
