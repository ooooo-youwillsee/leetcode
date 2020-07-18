package com.ooooo;

/**
 * dp
 * <p>
 * dp[i][j] ->  s1中前i个字符 和 s2中前j个字符， 能否组成s3中前i+j个字符
 *
 * @author leizhijie
 * @since 2020/7/18 15:48
 */
public class Solution2 {
  
  
  public boolean isInterleave(String s1, String s2, String s3) {
    int m = s1.length(), n = s2.length();
    if (m + n != s3.length()) return false;
    boolean[][] dp = new boolean[m + 1][n + 1];
    dp[0][0] = true;
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= n; j++) {
        // 两个值出现重叠
        if (i + 1 <= m)
          dp[i + 1][j] = dp[i + 1][j] || (dp[i][j] && s1.charAt(i) == s3.charAt(i + j));
        if (j + 1 <= n)
          dp[i][j + 1] = dp[i][j + 1] || (dp[i][j] && s2.charAt(j) == s3.charAt(i + j));
      }
    }
    return dp[s1.length()][s2.length()];
  }
  
  private static void test(String s1, String s2, String s3) {
    Solution2 solution = new Solution2();
    boolean b = solution.isInterleave(s1, s2, s3);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test("aabcc", "dbbca", "aadbbcbcac"); // true
    test("aabcc", "dbbca", "aadbbbaccc"); // false
  }
}
