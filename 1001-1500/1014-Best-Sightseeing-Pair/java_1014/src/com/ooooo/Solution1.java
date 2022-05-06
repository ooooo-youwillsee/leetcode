package com.ooooo;

/**
 * timeout
 */
class Solution1 {
  
  public int maxScoreSightseeingPair(int[] A) {
    int ans = Integer.MIN_VALUE;
    for (int i = 0; i < A.length; i++) {
      for (int j = i + 1; j < A.length; j++) {
        // 内层循环中 A[i] + i 是不变的， 如果结果要取最大值，也就是说 A[i] + i 是最大的。
        int num = A[i] + A[j] + i - j;
        ans = Math.max(ans, num);
      }
    }
    return ans;
  }
  
  private static void test(int[] A) {
    Solution1 solution = new Solution1();
    int ans = solution.maxScoreSightseeingPair(A);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    test(new int[]{8, 1, 5, 2, 6});
  }
}