package com.ooooo;

/**
 * dp  dp[i][j] 表示s中前i个字符和p中前j个字符是否匹配
 *
 * @author leizhijie
 * @since 2020/6/21 20:13
 */
public class Solution2 {

  public boolean isMatch(String s, String p) {
    int len_s = s.length(), len_p = p.length();
    boolean[][] dp = new boolean[len_s + 1][len_p + 1];
    dp[0][0] = true;
    for (int i = 0; i < p.length(); i++) {
      // ""  --> "**" || "b*"
      dp[0][i + 1] = p.charAt(i) == '*' && dp[0][i];
    }

    for (int i = 0; i < len_s; i++) {
      for (int j = 0; j < len_p; j++) {
        if (s.charAt(i) == p.charAt(j) || p.charAt(j) == '?') {
          dp[i + 1][j + 1] = dp[i][j];
        } else if (p.charAt(j) == '*') {
          // 一个字符 dp[i][j]     abcdf --> abc*f
          // 多个字符 dp[i][j + 1]   abccc --> abc*
          // 空字符 dp[i + 1][j]     abc --> abc*
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
