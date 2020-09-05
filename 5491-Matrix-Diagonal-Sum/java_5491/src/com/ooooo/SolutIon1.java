package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/9/5 22:55
 */
public class SolutIon1 {
	
	public int diagonalSum(int[][] mat) {
		if (mat.length == 0) return 0;
		int m = mat.length;
		int sum = 0;
		for (int i = 0; i < m; i++) {
			sum += mat[i][i] + mat[i][m - 1 - i];
		}
		return m % 2 == 0 ? sum : sum - mat[m / 2][m / 2];
	}
}
