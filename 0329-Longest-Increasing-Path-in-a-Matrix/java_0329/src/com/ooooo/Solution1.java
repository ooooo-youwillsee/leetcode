package com.ooooo;

/**
 * dfs +  memo
 */
class Solution1 {
  
  
  private int[][] matrix, memo;
  private int m, n;
  private int ans = 0;
  private final int[][] dx_dy = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  
  private boolean valid(int i, int j, int new_i, int new_j) {
    return (new_i >= 0 && new_i < m) && (new_j >= 0 && new_j < n)
        && (matrix[new_i][new_j] > matrix[i][j]);
  }
  
  private int dfs(int i, int j) {
    if (memo[i][j] != 0) return memo[i][j];
    int tempCount = 1;
    for (int[] d : dx_dy) {
      int new_i = i + d[0];
      int new_j = j + d[1];
      if (valid(i, j, new_i, new_j)) {
        tempCount = Math.max(tempCount, 1 + dfs(new_i, new_j));
      }
    }
    return memo[i][j] = tempCount;
  }
  
  public int longestIncreasingPath(int[][] matrix) {
    if (matrix.length == 0) return 0;
    this.matrix = matrix;
    this.m = matrix.length;
    this.n = matrix[0].length;
    memo = new int[m][n];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        ans = Math.max(ans, dfs(i, j));
      }
    }
    return ans;
  }
  
  
  private static void test(int[][] matrix) {
    Solution1 solution = new Solution1();
    int i = solution.longestIncreasingPath(matrix);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {3, 4, 5},
        {3, 2, 6},
        {2, 2, 1}
    }); // 4
    test(new int[][]{
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    }); // 4
    
  }
}