package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/6/20 10:00
 */
public class Solution2 {
  
  public boolean isMatch(String s, String p) {
    s = " " + s;
    p = " " + p;
    int len_s = s.length(), len_p = p.length();
    boolean[][] dp = new boolean[len_s + 1][len_p + 1];
    // s 或者 p 长度为0时，是无法匹配的
    for (int i = 0; i <= len_s; i++) {
      dp[i][0] = false;
    }
    for (int i = 0; i <= len_p; i++) {
      dp[0][i] = false;
    }
    // 都为0时，是可以匹配的
    dp[0][0] = true;
    
    for (int i = 0; i < len_s; i++) {
      for (int j = 0; j < len_p; j++) {
        if (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.') {
          dp[i + 1][j + 1] = dp[i][j];
        } else if (p.charAt(j) == '*') {
          if (s.charAt(i) != p.charAt(j - 1) && p.charAt(j - 1) != '.') {
            dp[i + 1][j + 1] = dp[i + 1][j - 1];
          } else {
            // 多个字符 abcc abc*
            // 一个字符 abcc abcc*
            // 没有字符 abc abcc*
            dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j] || dp[i + 1][j - 1];
          }
        }
      }
    }
    return dp[len_s][len_p];
  }
  
  private static void test(String s, String p) {
    Solution2 solution = new Solution2();
    boolean b = solution.isMatch(s, p);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test("aab", "c*a*b"); // true
    test("ab", ".*c"); // false
    test("aa", "a*"); // true
    test("aa", "a"); // false
    test("aab", "a*b"); // true
  }
}
