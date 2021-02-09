package main

import (
	"fmt"
)

func maxTurbulenceSize1(arr []int) int {
	if len(arr) <= 1 {
		return len(arr)
	}
	ans := 2
	if arr[0] == arr[1] {
		ans = 1
	}
	l, r := 0, 1
	for r+1 < len(arr) {
		if l == r {
			r++
			continue
		}
		if arr[r-1] > arr[r] && arr[r] < arr[r+1] {
			r++
		} else if arr[r-1] < arr[r] && arr[r] > arr[r+1] {
			r++
		} else {
			l++
		}
		ans = max(ans, r-l+1)
	}
	return ans
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	arr := []int{9, 4, 2, 10, 7, 8, 8, 1, 9}
	// arr := []int{9, 9}
	fmt.Println(maxTurbulenceSize(arr))

}
