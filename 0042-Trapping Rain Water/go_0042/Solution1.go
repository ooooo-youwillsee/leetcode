package main

// 从任意一点两边扩散
func trap1(height []int) int {
	ans := 0
	for i := 1; i < len(height)-1; i++ {
		left, right := 0, 0
		for j := i - 1; j >= 0; j-- {
			left = max(left, height[j])
		}
		for j := i + 1; j < len(height); j++ {
			right = max(right, height[j])
		}
		h := min(left, right)
		if h > height[i] {
			ans += h - height[i]
		}
	}
	return ans
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {

}
