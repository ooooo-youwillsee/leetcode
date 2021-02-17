package main

func matrixReshape(nums [][]int, r int, c int) [][]int {
	if r*c != len(nums)*len(nums[0]) {
		return nums
	}
	ans := make([][]int, r)
	for i := 0; i < r; i++ {
		ans[i] = make([]int, c)
	}

	ni, nj := 0, 0
	for _, row := range nums {
		for _, v := range row {
			ans[ni][nj] = v
			nj++
			if nj == c {
				ni++
				nj = 0
			}
		}
	}
	return ans
}

func main() {

}
