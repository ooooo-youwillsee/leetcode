package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/7/23 10:18
 */
public class Solution2 {
  
  
  public int minPathSum(int[][] grid) {
    int m = grid.length, n = grid[0].length;
    int[][] dp = new int[m + 1][n + 1];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0) {
          dp[i + 1][j + 1] = dp[i + 1][j] + grid[i][j];
        } else if (j == 0) {
          dp[i + 1][j + 1] = dp[i][j + 1] + grid[i][j];
        } else {
          dp[i + 1][j + 1] = Math.min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
        }
      }
    }
    return dp[m][n];
  }
  
  private static void test(int[][] grid) {
    Solution2 solution = new Solution2();
    int i = solution.minPathSum(grid);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    });
  }
}
