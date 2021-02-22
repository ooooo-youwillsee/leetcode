package main

func isToeplitzMatrix(matrix [][]int) bool {
	m, n := len(matrix), len(matrix[0])
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if check(i-1, j-1, m, n) {
				if matrix[i][j] != matrix[i-1][j-1] {
					return false
				}
			}
		}
	}
	return true
}

func check(i, j, m, n int) bool {
	return i >= 0 && i < m && j >= 0 && j < n
}

func main() {

}
