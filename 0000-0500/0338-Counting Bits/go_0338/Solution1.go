/**
* @Author: ooooo
* @Date: 2021/3/3 10:31
 */

package main

func countBits(num int) []int {
	if num <= 0 {
		return []int{0}
	}
	ans := make([]int, num+1)
	ans[1] = 1
	for i := 2; i <= num; i++ {
		if i%2 == 0 {
			ans[i] = ans[i/2]
		} else {
			ans[i] = ans[i-1] + 1
		}
	}
	return ans
}

func main() {

}
