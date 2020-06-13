package com.ooooo;

class Solution1 {
  
  public int climbStairs(int n) {
    if (n == 1 || n == 2) return n;
    int[] dp = new int[n + 1];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
  
  private static void test(int n) {
    Solution1 solution = new Solution1();
    int ans = solution.climbStairs(n);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    test(2); // 2
    test(3); // 3
  }
}