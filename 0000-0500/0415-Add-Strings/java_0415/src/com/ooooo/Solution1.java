package com.ooooo;

class Solution1 {
  
  public String addStrings(String num1, String num2) {
    StringBuilder sb = new StringBuilder();
    int carry = 0;
    int i = num1.length() - 1, j = num2.length() - 1;
    while (i >= 0 || j >= 0) {
      int a = i < 0 ? 0 : num1.charAt(i--) - '0';
      int b = j < 0 ? 0 : num2.charAt(j--) - '0';
      char num = (char) (((a + b + carry) % 10) + '0');
      sb.append(num);
      carry = (a + b + carry) / 10;
    }
    if (carry > 0) sb.append('1');
    return sb.reverse().toString();
  }
  
  private static void test(String num1, String num2) {
    Solution1 solution = new Solution1();
    String s = solution.addStrings(num1, num2);
    System.out.println(s);
  }
  
  public static void main(String[] args) {
    test("19", "99"); // 118
  }
}