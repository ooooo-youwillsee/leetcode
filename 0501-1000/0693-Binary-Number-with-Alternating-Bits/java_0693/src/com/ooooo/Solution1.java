package com.ooooo;

class Solution1 {
  
  public boolean hasAlternatingBits(int n) {
    int prev = n & 1;
    n >>= 1;
    while (n > 0) {
      if (prev == (n & 1)) return false;
      prev = n & 1;
      n >>= 1;
    }
    return true;
  }
  
  private static void test(int n) {
    Solution1 solution = new Solution1();
    boolean b = solution.hasAlternatingBits(n);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test(5); // true
    test(7); // false
  }
}