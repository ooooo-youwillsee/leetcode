package com.ooooo;

class Solution1 {
  
  public int countBinarySubstrings(String s) {
    if (s == null || s.length() == 0) return 0;
    int prev = 0, cur = 1, i = 0;
    int sum = 0;
    while (i < s.length()) {
      while (i + 1 < s.length() && s.charAt(i) == s.charAt(i + 1)) {
        cur++;
        i++;
      }
      sum += Math.min(prev, cur);
      prev = cur;
      cur = 1;
      i++;
    }
    return sum;
  }
  
  
  private static void test(String s) {
    Solution1 solution = new Solution1();
    int i = solution.countBinarySubstrings(s);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test("00110011"); // 6
    test("10101"); // 4
  }
}