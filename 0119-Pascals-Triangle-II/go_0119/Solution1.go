package main

func getRow(rowIndex int) []int {
	ans := []int{1}
	for i := 0; i < rowIndex; i++ {
		a, b := 1, 0
		for j := 1; j < len(ans); j++ {
			b = ans[j]
			ans[j] = b + a
			a = b
		}
		ans = append(ans, 1)
	}
	return ans
}

func main() {

}
