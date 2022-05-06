package com.ooooo;

class Solution1 {

  public int waysToStep(int n) {
    if (n == 0 || n == 1) return 1;
    if (n == 2) return 2;
    long[] dp = new long[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
      dp[i] = (dp[i - 1] +  dp[i - 2] + dp[i - 3]) % 1000000007;
    }
    return (int) (dp[n] % 1000000007);
  }

  private static void test(int num) {
    Solution1 solution = new Solution1();
    int ans = solution.waysToStep(num);
    System.out.println(ans);
  }

  public static void main(String[] args) {
    test(3); // 4
    test(5); // 13
  }
}