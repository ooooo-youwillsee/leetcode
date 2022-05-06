package com.ooooo;

class Solution1 {
  
  public boolean judgeSquareSum(int c) {
    int k = (int) Math.sqrt(c) + 1;
    for (int a = 0; a < k; a++) {
      int o = c - a * a;
      int b = (int) Math.sqrt(o);
      if (b * b == o) return true;
    }
    return false;
  }
  
  
  private static void test(int c) {
    Solution1 solution = new Solution1();
    boolean b = solution.judgeSquareSum(c);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test(5); // true
    test(3); // false
  }
}