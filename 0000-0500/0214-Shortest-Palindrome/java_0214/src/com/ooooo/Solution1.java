package com.ooooo;

/**
 * 中心扩展 timeout
 */
class Solution1 {
  
  public String shortestPalindrome(String s) {
    StringBuilder sb = new StringBuilder(s);
    sb.reverse();
    
    while (true) {
      int len = sb.length();
      boolean flag = true;
      for (int l = len % 2 == 1 ? len / 2 - 1 : (len - 1) / 2, r = (len + 1) / 2; l >= 0 && r < len; l--, r++) {
        if (sb.charAt(r) == '-') {
          sb.setCharAt(r, sb.charAt(l));
        }
        if (sb.charAt(l) != sb.charAt(r)) {
          sb.append("-");
          flag = false;
          break;
        }
      }
      if (flag) break;
    }
    return sb.reverse().toString();
  }
  
  private static void test(String s) {
    Solution1 solution = new Solution1();
    String palindrome = solution.shortestPalindrome(s);
    System.out.println(palindrome);
  }
  
  public static void main(String[] args) {
    test("aacecaaa"); // aaacecaaa
    test("abcd"); // dcbabcd
  }
}