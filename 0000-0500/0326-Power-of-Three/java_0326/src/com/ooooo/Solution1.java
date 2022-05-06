package com.ooooo;

/**
 *
 */
class Solution1 {
  
  public boolean isPowerOfThree(int n) {
    if (n == 1) return true;
    if (n == 0 || n % 3 != 0) return false;
    return isPowerOfThree(n / 3);
  }
  
  private static void test(int n) {
    Solution1 solution = new Solution1();
    boolean ans = solution.isPowerOfThree(n);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    test(1);
    test(27);
    test(0);
    test(9);
    test(45);
  }
}