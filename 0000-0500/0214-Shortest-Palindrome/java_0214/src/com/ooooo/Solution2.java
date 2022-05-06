package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/8/29 11:44
 */
public class Solution2 {
  
  public String shortestPalindrome(String s) {
    StringBuilder sb = new StringBuilder(s);
    sb.reverse();
    int i = 0, len = sb.length();
    while (!sb.substring(i, len).equals(s.substring(0, len - i))) {
      i++;
    }
    return sb.substring(0, i) + s;
  }
  
  private static void test(String s) {
    Solution2 solution = new Solution2();
    String palindrome = solution.shortestPalindrome(s);
    System.out.println(palindrome);
  }
  
  public static void main(String[] args) {
    test("aacecaaa"); // aaacecaaa
    test("abcd"); // dcbabcd
  }
}
