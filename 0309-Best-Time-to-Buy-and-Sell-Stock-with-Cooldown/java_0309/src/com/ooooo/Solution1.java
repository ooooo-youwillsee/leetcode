package com.ooooo;

/**
 * dp
 * <p>
 * <p>
 * dp[i][j] 表示第i天，j （1持有，0不持有）
 * <p>
 * dp[i][1] =  max( dp[i-2][0] -p, dp[i-1][1])
 * dp[i][0] =  max( dp[i-1][1] + p, dp[i-1][0])
 */
class Solution1 {

  public int maxProfit(int[] prices) {
    int n = prices.length, profit = 0;
    int[][] dp = new int[n + 1][2];
    dp[0][1] = Integer.MIN_VALUE;
    for (int i = 0; i < n; i++) {
      int p = prices[i];
      dp[i + 1][1] = Math.max(i - 1 <= 0 ? dp[i][0] - p : (dp[i - 1][0] - p), dp[i][1]);
      dp[i + 1][0] = Math.max(dp[i][1] + p, dp[i][0]);
      profit = Math.max(profit, dp[i + 1][0]);
    }
    return profit;
  }

  private static void test(int[] prices) {
    Solution1 solution = new Solution1();
    int i = solution.maxProfit(prices);
    System.out.println(i);
  }

  public static void main(String[] args) {
    test(new int[]{1, 2, 3, 0, 2}); // 3
  }
}