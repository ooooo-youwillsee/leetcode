package com.ooooo;

class Solution1 {
  
  public boolean isValid(String s) {
    StringBuilder sb = new StringBuilder(s);
    while (true) {
      int len = sb.length();
      for (int i = 0; i < sb.length() - 1; i++) {
        char a = sb.charAt(i), b = sb.charAt(i + 1);
        if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}')) {
          sb.delete(i, i + 2);
          break;
        }
      }
      if (len == sb.length()) break;
    }
    return sb.length() == 0;
  }
  
  
  private static void test(String s) {
    Solution1 solution = new Solution1();
    boolean valid = solution.isValid(s);
    System.out.println(valid);
  }
  
  public static void main(String[] args) {
    test("()[]{}"); // true
    test("([)]"); // false
  }
}