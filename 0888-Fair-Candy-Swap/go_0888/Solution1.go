/**
* @Author: ooooo
* @Date: 2021/2/6 18:37
 */

package go_088

func fairCandySwap(A []int, B []int) []int {
	sumA, sumB := sum(A), sum(B)
	mid := sumA + (sumB-sumA)/2
	for i := range A {
		for j := range B {
			if A[j]-B[j] == sumA-mid {
				return []int{A[i], B[j]}
			}
		}
	}
	return nil
}

func sum(nums []int) int {
	ans := 0
	for _, v := range nums {
		ans += v
	}
	return ans
}
