package com.ooooo;

class Solution1 {
  
  public boolean repeatedSubstringPattern(String s) {
    if (s.length() == 1) return false;
    String check_str = s.substring(1) + s;
    return check_str.indexOf(s) < s.length() - 1;
  }
  
  private static void test(String s) {
    Solution1 solution = new Solution1();
    boolean b = solution.repeatedSubstringPattern(s);
    System.out.println(b);
  }
  
  
  public static void main(String[] args) {
    test("abab");
    test("aba");
  }
}

