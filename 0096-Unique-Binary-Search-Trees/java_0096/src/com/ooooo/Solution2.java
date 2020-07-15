package com.ooooo;

/**
 * dp
 * @author leizhijie
 * @since 2020/7/15 20:44
 */
public class Solution2 {
  
  
  public int numTrees(int n) {
    if (n == 0 || n == 1) return 1;
    int[] dp = new int[n + 1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      int sum = 0;
      for (int j = 0; j < i; j++) {
        sum += dp[j] * dp[i - 1 - j];
      }
      dp[i] =  sum;
    }
    return dp[n];
  }
  
  private static void test(int n) {
    Solution2 solution = new Solution2();
    int i = solution.numTrees(n);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(3); // 5
  }
}
