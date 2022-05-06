package main

import (
	"sort"
)

var ans = make([][]int, 0)

func dfs(nums []int, i int, tmp []int) {
	dst := make([]int, len(tmp))
	copy(dst, tmp)
	ans = append(ans, dst)
	if i == len(nums) {
		return
	}
	for j := i; j < len(nums); j++ {
		if j > i && nums[j] == nums[j-1] {
			continue
		}
		tmp = append(tmp, nums[j])
		dfs(nums, j+1, tmp)
		tmp = tmp[:len(tmp)-1]
	}
}

func subsetsWithDup(nums []int) [][]int {
	ans = make([][]int, 0)
	sort.Ints(nums)
	dfs(nums, 0, make([]int, 0))
	return ans
}

func main() {

}
