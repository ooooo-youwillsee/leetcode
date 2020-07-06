package com.ooooo;

/**
 * dp  dp[i][j] 表示下标 0,0 到 i,j 的路径总数
 */
class Solution1 {

  public int uniquePathsWithObstacles(int[][] obstacleGrid) {
    if (obstacleGrid == null || obstacleGrid.length == 0) return 0;
    int m = obstacleGrid.length, n = obstacleGrid[0].length;
    int[][] dp = new int[m + 1][n + 1];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (obstacleGrid[i][j] == 1) {
          dp[i + 1][j + 1] = 0;
        } else {
          if (i == 0 && j == 0) {
            dp[i + 1][j + 1] = 1;
          } else {
            dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1];
          }
        }
      }
    }
    return dp[m][n];
  }

  private static void test(int[][] grid) {
    Solution1 solution = new Solution1();
    int n = solution.uniquePathsWithObstacles(grid);
    System.out.println(n);
  }

  public static void main(String[] args) {
    test(new int[][]{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    });
  }
} 