package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/9/1 20:37
 */
public class Solution2 {
  
  public boolean PredictTheWinner(int[] nums) {
    int n = nums.length;
    int[][] dp = new int[n][n];
    for (int i = 0; i < n; i++) {
      dp[i][i] = nums[i];
    }
    // 这里是确保 i < j
    for (int i = n - 2; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        dp[i][j] = Math.max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
      }
    }
    return dp[0][n - 1] >= 0;
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    boolean b = solution.PredictTheWinner(nums);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 5, 2}); // false
    test(new int[]{1, 5, 233, 7}); // true
  }
}
