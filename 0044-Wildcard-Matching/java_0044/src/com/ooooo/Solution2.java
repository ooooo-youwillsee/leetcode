package com.ooooo;

/**
 *
 * dp
 * @author leizhijie
 * @since 2020/6/21 20:13
 */
public class Solution2 {
  
  public boolean isMatch(String s, String p) {
    int len_s = s.length(), len_p = p.length();
    boolean[][] dp = new boolean[len_s + 1][len_p + 1];
    dp[0][0] = true;
    for (int i = 1; i <= len_s; i++) {
      // 这句话就是废话，默认就是false
      dp[i][0] = false;
    }
    for (int i = 1; i <= len_p; i++) {
      // 处理 p 为 '****'的情况
      dp[0][i] = dp[0][i - 1] && p.charAt(i - 1) == '*';
    }
    
    for (int i = 0; i < len_s; i++) {
      for (int j = 0; j < len_p; j++) {
        if (s.charAt(i) == p.charAt(j) || p.charAt(j) == '?') {
          dp[i + 1][j + 1] = dp[i][j];
        } else if (p.charAt(j) == '*') {
          // 一个字符 dp[i][j]
          // 多个字符 dp[i][j + 1]
          // 空字符 dp[i + 1][j]
          dp[i + 1][j + 1] = dp[i][j] || dp[i][j + 1] || dp[i + 1][j];
        }
        //  其他情况就是false
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
    test("", "?"); // false
    test("", "*"); // true
    test("adceb", "*a*b"); // true
    test("aa", "*"); // true
    test("aa", "a"); // false
    test("cb", "?a"); // false
  }
}
