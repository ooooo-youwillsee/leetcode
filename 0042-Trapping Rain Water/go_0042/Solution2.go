package main

func trap(height []int) int {
	ans, sz := 0, len(height)
	left, right := make([]int, sz), make([]int, sz)
	for i := 1; i < len(height); i++ {
		left[i] = max(left[i-1], height[i-1])
	}
	for i := len(height) - 2; i >= 0; i-- {
		right[i] = max(right[i+1], height[i+1])
	}
	for i := 1; i < len(height)-1; i++ {
		h := min(left[i], right[i])
		if h > height[i] {
			ans += h - height[i]
		}
	}
	return ans
}

func main() {
}
