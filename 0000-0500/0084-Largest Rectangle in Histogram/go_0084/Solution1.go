package main

// 寻找左右两边第一个满足条件的数字， 单调栈
func largestRectangleArea(heights []int) int {
	sz := len(heights)
	ans := 0
	var stack = []int{}

	// 找到左边第一个小的数
	left := make([]int, sz)
	for i := 0; i < sz; i++ {
		for len(stack) > 0 && heights[stack[len(stack)-1]] >= heights[i] {
			stack = stack[:len(stack)-1]
		}
		if len(stack) > 0 {
			left[i] = stack[len(stack)-1]
		} else {
			left[i] = -1
		}
		stack = append(stack, i)
	}

	right := make([]int, sz)
	stack = []int{}
	for i := sz - 1; i >= 0; i-- {
		for len(stack) > 0 && heights[stack[len(stack)-1]] > heights[i] {
			stack = stack[:len(stack)-1]
		}
		if len(stack) > 0 {
			right[i] = stack[len(stack)-1]
		} else {
			right[i] = sz
		}
		stack = append(stack, i)
	}

	for i := 0; i < sz; i++ {
		ans = max(ans, (right[i]-left[i]-1)*heights[i])
	}

	return ans
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}
