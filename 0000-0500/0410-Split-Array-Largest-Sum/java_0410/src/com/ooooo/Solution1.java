package com.ooooo;

import java.util.Arrays;

/**
 * dp
 */
class Solution1 {
  
  public int splitArray(int[] nums, int m) {
    int n = nums.length;
    int[][] dp = new int[n + 1][m + 1];
    for (int[] ints : dp) {
      Arrays.fill(ints, Integer.MAX_VALUE);
    }
    dp[0][0] = 0;
    int[] sum = new int[n + 1];
    for (int i = 0; i < nums.length; i++) {
      sum[i + 1] = sum[i] + nums[i];
    }
    for (int i = 1; i <= n; i++) {
      // i个元素最多只能分i段
      for (int j = 1; j <= Math.min(i, m); j++) {
        for (int k = 0; k < i; k++) {
          // k个元素为j-1段，j后面的元素分为一段
          dp[i][j] = Math.min(dp[i][j], Math.max(dp[k][j - 1], sum[i] - sum[k]));
        }
      }
    }
    return dp[n][m];
  }
  
  private static void test(int[] nums, int m) {
    Solution1 solution = new Solution1();
    int i = solution.splitArray(nums, m);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{7, 2, 5, 10, 8}, 2);
  }
}