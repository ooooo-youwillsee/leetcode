package com.ooooo;

class Solution1 {
  
  public int[][] transpose(int[][] A) {
    int m = A.length, n = A[0].length;
    int[][] ans = new int[n][m];
    for (int i = 0; i < A.length; i++) {
      for (int j = 0; j < A[i].length; j++) {
        ans[j][i] = A[i][j];
      }
    }
    return ans;
  }
  
  private static void test(int[][] A) {
    Solution1 solution = new Solution1();
    int[][] transpose = solution.transpose(A);
    for (int[] row : transpose) {
      for (int i : row) {
        System.out.print(i + " ");
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
        {1, 2, 3},
        {4, 5, 6}
    });
  }
}