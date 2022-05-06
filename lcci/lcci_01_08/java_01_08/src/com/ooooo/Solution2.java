package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/5/2 13:41
 */
public class Solution2 {

  public void setZeroes(int[][] matrix) {
    if (matrix == null) return;
    boolean row_0 = false, col_0 = false; // 记录第一行或者第一列为0
    for (int i = 0; i < matrix.length; i++) {
      for (int j = 0; j < matrix[0].length; j++) {
        if (matrix[i][j] == 0) {
          if (i == 0) row_0 = true;
          if (j == 0) col_0 = true;
          // 用第一行和第一列的数据来保存 0
          matrix[0][j] = matrix[i][0] = 0;
        }
      }
    }

    for (int i = 1; i < matrix.length; i++)
      for (int j = 1; j < matrix[0].length; j++) {
        if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
      }

    if (col_0) {
      for (int k = 0; k < matrix.length; k++) {
        matrix[k][0] = 0;
      }
    }
    if (row_0) {
      for (int k = 0; k < matrix[0].length; k++) {
        matrix[0][k] = 0;
      }
    }
  }

  private static void test(int[][] matrix) {
    Solution2 solution = new Solution2();
    solution.setZeroes(matrix);
    for (int[] ints : matrix) {
      for (int anInt : ints) {
        System.out.print(anInt + " ");
      }
      System.out.println();
    }
    System.out.println();
  }

  public static void main(String[] args) {
    test(new int[][]{
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    });
  }
}
