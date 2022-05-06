package com.ooooo;

class Solution1 {
  
  public String convertToBase7(int num) {
    if (num == 0) return "0";
    StringBuilder sb = new StringBuilder();
    int n = num < 0 ? -num : num;
    while (n > 0) {
      sb.append(n % 7);
      n /= 7;
    }
    if (num < 0) sb.append("-");
    return sb.reverse().toString();
  }
  
  private static void test(int num) {
    Solution1 solution = new Solution1();
    String s = solution.convertToBase7(num);
    System.out.println(s);
  }
  
  public static void main(String[] args) {
    test(100); // 202
    test(101); // 203
    test(-7); // -10
  }
}