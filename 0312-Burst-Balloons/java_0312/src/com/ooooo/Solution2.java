package com.ooooo;

import java.util.Arrays;

/**
 *
 * 分治
 * @author leizhijie
 * @since 2020/7/19 17:37
 */
public class Solution2 {
  
  public int[][] rec;
  public int[] val;
  
  public int maxCoins(int[] nums) {
    int n = nums.length;
    val = new int[n + 2];
    for (int i = 1; i <= n; i++) {
      val[i] = nums[i - 1];
    }
    val[0] = val[n + 1] = 1;
    rec = new int[n + 2][n + 2];
    for (int i = 0; i <= n + 1; i++) {
      Arrays.fill(rec[i], -1);
    }
    return solve(0, n + 1);
  }
  
  public int solve(int left, int right) {
    if (left >= right - 1) {
      return 0;
    }
    if (rec[left][right] != -1) {
      return rec[left][right];
    }
    // 最后一个戳破的是i
    for (int i = left + 1; i < right; i++) {
      int sum = val[left] * val[i] * val[right];
      sum += solve(left, i) + solve(i, right);
      rec[left][right] = Math.max(rec[left][right], sum);
    }
    return rec[left][right];
  }
  
  private static void test(int[] nums) {
    Solution2 solution = new Solution2();
    int i = solution.maxCoins(nums);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{3, 1, 5, 8}); // 167
  }
}
