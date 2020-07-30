package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/7/30 15:19
 */
public class Solution2 {
  
  
  public int integerBreak(int n) {
    int[] dp = new int[n + 1];
    for (int i = 2; i <= n; i++) {
      int max = 1;
      for (int j = 1; j < i; j++) {
        max = Math.max(j * (i - j), max);
        max = Math.max(j * dp[i - j], max);
      }
      dp[i] = max;
    }
    return dp[n];
  }
  
  
  private static void test(int n) {
    Solution2 solution = new Solution2();
    int i = solution.integerBreak(n);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(2); // 1
    test(10); // 36
    test(8); // 18
  }
  
  
}
