package com.ooooo;

/**
 * dp(贪心法)
 *
 * @author leizhijie
 * @since 2020/6/17 11:59
 */
public class Solution2 {
  
  /**
   * i < j
   * ( A[i] + i ) + ( A[j] - j ) ==> left + right => 在循环过程中记录 left 的最大值
   */
  public int maxScoreSightseeingPair(int[] A) {
    int ans = Integer.MIN_VALUE, left_max = A[0];
    for (int i = 1; i < A.length; i++) {
      ans = Math.max(ans, left_max + A[i] - i);
      left_max = Math.max(left_max, A[i] + i);
    }
    return ans;
  }
  
  private static void test(int[] A) {
    Solution2 solution = new Solution2();
    int ans = solution.maxScoreSightseeingPair(A);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    test(new int[]{8, 1, 5, 2, 6});
  }
}
