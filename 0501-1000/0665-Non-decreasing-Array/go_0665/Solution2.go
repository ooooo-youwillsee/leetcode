/**
* @Author: ooooo
* @Date: 2021/2/7 11:18
 */

package main

func checkPossibility(nums []int) bool {
	changed := false
	if len(nums) <= 2 {
		return true
	}
	if nums[0] > nums[1] {
		changed = true
	}
	for i := 1; i < len(nums)-1; i++ {
		left, cur, right := nums[i-1], nums[i], nums[i+1]
		if cur > right {
			if changed {
				return false
			}
			if left <= right {
				// cur 变小
				nums[i] = left
			} else {
				// right 变大
				nums[i+1] = cur
			}
			changed = true
		}
	}
	return true
}
