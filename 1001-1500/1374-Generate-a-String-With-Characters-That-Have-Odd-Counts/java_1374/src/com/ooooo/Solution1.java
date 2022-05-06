package com.ooooo;

class Solution1 {
  
  public String generateTheString(int n) {
    StringBuilder sb = new StringBuilder();
    if (n % 2 == 0) {
      sb.append("a");
      for (int i = 0; i < n - 1; i++) {
        sb.append("b");
      }
    } else {
      for (int i = 0; i < n; i++) {
        sb.append("b");
      }
    }
    return sb.toString();
  }
  
  private static void test(int n) {
    Solution1 solution = new Solution1();
    String s = solution.generateTheString(n);
    System.out.println(s);
  }
  
  public static void main(String[] args) {
    test(4);
    test(5);
  }
}