package com.ooooo;

class Solution1 {
  
  public String convertToTitle(int n) {
    StringBuilder sb = new StringBuilder();
    while (n > 0) {
      int c = n % 26 == 0 ? 26 : n % 26;
      n = (n - c) / 26;
      sb.append((char) (c - 1 + 'A'));
    }
    return sb.reverse().toString();
  }
  
  private static void test(int n) {
    Solution1 solution = new Solution1();
    String ans = solution.convertToTitle(n);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    // A * 26 + Z * 1 = 52
    test(52); // AZ
    test(1); // A
    test(28); // AB
    test(701); // ZY
  }
}