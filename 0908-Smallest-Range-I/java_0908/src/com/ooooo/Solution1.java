package com.ooooo;

class Solution1 {
  
  public int smallestRangeI(int[] A, int K) {
    int max = A[0], min = A[0];
    for (int i : A) {
      max = Math.max(max, i);
      min = Math.min(min, i);
    }
    return Math.max(0, max - min - 2 * K);
  }
  
  
  private static void test(int[] A, int k) {
    Solution1 solution = new Solution1();
    int i = solution.smallestRangeI(A, k);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{0, 10}, 2); // 6
  }
}