package com.ooooo;

/**
 *
 * * 分为两种情况，(1-n) 和 (0)
 */
class Solution1 {
  
  private boolean isMatch(char c1, char c2) {
    return c1 == c2 || c2 == '.';
  }
  
  private boolean isMatch(String s, int i, String p, int j) {
    if (i == s.length() && j == p.length()) return true;
    if (j >= p.length()) return false;
    
    if (j + 1 < p.length() && p.charAt(j + 1) == '*') {
      boolean b = i < s.length() && isMatch(s.charAt(i), p.charAt(j)) && isMatch(s, i + 1, p, j);
      return b || isMatch(s, i, p, j + 2);
    }
    return i < s.length() && isMatch(s.charAt(i), p.charAt(j)) && isMatch(s, i + 1, p, j + 1);
  }
  
  public boolean isMatch(String s, String p) {
    return isMatch(s, 0, p, 0);
  }
  
  private static void test(String s, String p) {
    Solution1 solution = new Solution1();
    boolean b = solution.isMatch(s, p);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test("ab", ".*c"); // false
    test("aa", "a*"); // true
    test("aa", "a"); // false
    test("aab", "a*b"); // true
  }
}