package com.ooooo;

class Solution1 {
  
  private boolean check(int i, int j, int[][] matrix) {
    int num = matrix[i++][j++];
    while (i < matrix.length && j < matrix[0].length) {
      if (matrix[i++][j++] != num) {
        return false;
      }
    }
    return true;
  }
  
  public boolean isToeplitzMatrix(int[][] matrix) {
    for (int i = 0; i < matrix[0].length; i++) {
      if (!check(0, i, matrix)) return false;
    }
    for (int i = 1; i < matrix.length; i++) {
      if (!check(i, 0, matrix)) return false;
    }
    return true;
  }
  
  private static void test(int[][] matrix) {
    Solution1 solution = new Solution1();
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