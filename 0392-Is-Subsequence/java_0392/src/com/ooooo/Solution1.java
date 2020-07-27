package com.ooooo;

class Solution1 {
  
  public boolean isSubsequence(String s, String t) {
    int i = 0, j = 0;
    while (j < t.length() && i < s.length() ) {
      if (s.charAt(i) == t.charAt(j)) i++;
      j++;
    }
    return i == s.length();
  }
  
  private static void test(String s, String t) {
    Solution1 solution = new Solution1();
    boolean b = solution.isSubsequence(s, t);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test("abc", "ahbgdc"); // true
    test("axc", "ahbgdc"); // false
  }
}