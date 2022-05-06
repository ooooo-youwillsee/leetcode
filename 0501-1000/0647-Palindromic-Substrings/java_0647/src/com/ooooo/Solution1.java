package com.ooooo;

/**
 * 中心扩展
 */
class Solution1 {
  
  private int count(String s, int l, int r) {
    if (l >= r) return 0;
    int len = (r - l - 1) / 2;
    int count = 0;
    for (int i = l + len, j = r - len; i >= l && j <= r; i--, j++) {
      if (s.charAt(i) == s.charAt(j)) count++;
      else break;
    }
    return count;
  }
  
  public int countSubstrings(String s) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
      count += count(s, i, s.length() - 1);
      if (i < s.length() - 1) {
        count += count(s, 0, i);
      }
    }
    return count + s.length();
  }
  
  
  private static void test(String s) {
    Solution1 solution = new Solution1();
    int i = solution.countSubstrings(s);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test("hello"); // 7
    test("aaaaa"); // 15
    test("aaa"); // 6
    test("abc"); // 3
  }
}