package com.ooooo;

class Solution1 {
  
  public boolean isPowerOfFour(int num) {
    if (num == 1) return true;
    if (num == 0 || num % 4 != 0) return false;
    return isPowerOfFour(num / 4);
  }
  
  private static void test(int n) {
    Solution1 solution = new Solution1();
    boolean ans = solution.isPowerOfFour(n);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    test(1);
    test(16);
    test(5);
    int num = 1;
    
    for (int i = 0; i < 20; i++) {
      num *= 4;
      System.out.print(num + " ");
      if (num > Integer.MAX_VALUE) break;
    }
  }
}