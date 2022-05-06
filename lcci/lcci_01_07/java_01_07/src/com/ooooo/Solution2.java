package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/5/1 12:26
 */
public class Solution2 {

  private void swap(int[][] matrix, int i, int j, int to_i, int to_j) {
    int temp = matrix[i][j];
    matrix[i][j] = matrix[to_i][to_j];
    matrix[to_i][to_j] = temp;
  }

  public void rotate(int[][] matrix) {
    if (matrix == null || matrix.length == 0) return;
    int row = matrix.length, col = matrix[0].length;

    for (int r = 0; r < row / 2; r++) {
      for (int k = r; k < col - r - 1; k++) {
        swap(matrix, r, k, k, col - 1 - r);
      }
      for (int k = r; k < col - r - 1; k++) {
        swap(matrix, r, k, row - 1 - r, col - 1 - k);
      }
      for (int k = r; k < col - r - 1; k++) {
        swap(matrix, r, k, row - 1 - k, r);
      }

      // swap(matrix, 0, 0, 0, col - 1);
      // swap(matrix, 0, 1, 1, col - 1);
      //
      // swap(matrix, 0, 0, row - 1, col - 1);
      // swap(matrix, 0, 1, row - 1, col - 2);
      //
      // swap(matrix, 0, 0, row - 1, 0);
      // swap(matrix, 0, 1, row - 2, 0);
    }
  }


  private static void test(int[][] martrix) {
    Solution2 solution = new Solution2();
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

    test(new int[][]{
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    });
  }
}
