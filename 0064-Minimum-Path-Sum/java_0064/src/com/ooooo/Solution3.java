package com.ooooo;

/**
 * dp optimize
 * @author leizhijie
 * @since 2020/7/23 10:35
 */
public class Solution3 {
  
  
  public int minPathSum(int[][] grid) {
    int m = grid.length, n = grid[0].length;
    int[] dp = new int[n + 1];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0) {
          dp[j + 1] = dp[j] + grid[i][j];
        } else if (j == 0) {
          dp[j + 1] = dp[j + 1] + grid[i][j];
        } else {
          dp[j + 1] = Math.min(dp[j], dp[j + 1]) + grid[i][j];
        }
      }
    }
    return dp[n];
  }
  
  private static void test(int[][] grid) {
    Solution3 solution = new Solution3();
    int i = solution.minPathSum(grid);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    });
    
    test(new int[][]{
        {1, 2},
        {1, 1}
    });
  }
}
