package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/8/3 10:12
 */
public class Solution2 {
  
  public boolean isToeplitzMatrix(int[][] matrix) {
    for (int i = 1; i < matrix.length; i++) {
      for (int j = 1; j < matrix[0].length; j++) {
        if (matrix[i][j] != matrix[i - 1][j - 1]) return false;
      }
    }
    return true;
  }
  
  private static void test(int[][] matrix) {
    Solution2 solution = new Solution2();
    boolean b = solution.isToeplitzMatrix(matrix);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {1, 2, 3, 4},
        {5, 1, 2, 3},
        {9, 5, 1, 2}
    }); // true
    
    test(new int[][]{
        {1, 2},
        {2, 2}
    }); // false
  }
  
}
