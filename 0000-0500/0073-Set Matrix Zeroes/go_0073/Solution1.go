/**
* @Author: ooooo
* @Date: 2021/3/21 15:35
 */

package main

func setZeroes(matrix [][]int) {
	firstCol, firstRow := false, false
	m, n := len(matrix), len(matrix[0])

	for i := 0; i < n; i++ {
		if matrix[0][i] == 0 {
			firstRow = true
		}
	}

	for i := 0; i < m; i++ {
		if matrix[i][0] == 0 {
			firstCol = true
		}
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if matrix[i][j] == 0 {
				matrix[0][j] = 0
				matrix[i][0] = 0
			}
		}
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if matrix[0][j] == 0 || matrix[i][0] == 0 {
				matrix[i][j] = 0
			}
		}
	}

	if firstCol {
		for i := 0; i < m; i++ {
			matrix[i][0] = 0
		}
	}

	if firstRow {
		for i := 0; i < n; i++ {
			matrix[0][i] = 0
		}
	}
}
