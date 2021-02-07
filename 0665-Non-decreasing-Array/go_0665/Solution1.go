/**
* @Author: ooooo
* @Date: 2021/2/7 09:37
 */

package main

import (
	"fmt"
)

func check(nums []int) bool {
	for i := 0; i < len(nums)-1; i++ {
		if nums[i] > nums[i+1] {
			return false
		}
	}
	return true
}

func checkPossibility1(nums []int) bool {
	changed := false
	for i := 0; i < len(nums)-1; i++ {
		if nums[i] > nums[i+1] {
			if changed {
				return false
			}
			a := nums[i]
			nums[i] = nums[i+1]
			if check(nums) {
				return true
			}
			nums[i], nums[i+1] = a, a
			if check(nums) {
				return true
			}
			changed = true
		}
	}
	return true
}

func main() {
	nums := []int{4, 2, 3}
	fmt.Println(checkPossibility(nums))
}
