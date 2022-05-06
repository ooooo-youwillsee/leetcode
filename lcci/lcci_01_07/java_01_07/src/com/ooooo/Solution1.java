package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/5/1 12:10
 */
public class Solution1 {

  public void rotate(int[][] matrix) {
    if (matrix == null || matrix.length == 0) return;
    int row = matrix.length, col = matrix[0].length;
    int[][] tmp = new int[row][col];
    for (int i = 0; i < row; i++) {
      System.arraycopy(matrix[i], 0, tmp[i], 0, col);
    }
    for (int i = col - 1; i >= 0; i--) {
      for (int j = 0; j < row; j++) {
        matrix[j][i] = tmp[col - 1 - i][j];
      }
    }
  }

  private static void test(int[][] martrix) {
    Solution1 solution = new Solution1();
    solution.rotate(martrix);
    for (int[] ints : martrix) {
      for (int anInt : ints) {
        System.out.print(anInt + " ");
      }
      System.out.println();
    }
    System.out.println();
  }

  public static void main(String[] args) {
    test(new int[][]{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    });
  }
}
