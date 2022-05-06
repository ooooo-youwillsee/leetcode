package com.ooooo;


/**
 * dp -> dp[i] 表示以下标 i 字符结尾的最长有效括号的长度
 * <p>
 * 有两种情况， ()  或者 ))
 */
class Solution1 {

  public int longestValidParentheses(String s) {
    int n = s.length(), ans = 0;
    int[] dp = new int[n + 1];
    for (int i = 0; i < n; i++) {
      if (s.charAt(i) == ')' && i - 1 >= 0) {
        if (s.charAt(i - 1) == '(') {
          dp[i + 1] = dp[i - 1] + 2;
        } else {
          if (i - dp[i] - 1 >= 0 && s.charAt(i - dp[i] - 1) == '(') {
            dp[i + 1] = dp[i] + 2 + (i - dp[i] - 1 >= 0 ? dp[i - dp[i] - 1] : 0);
          }
        }
      }
      ans = Math.max(ans, dp[i + 1]);
    }
    return ans;
  }

  private static void test(String s) {
    Solution1 solution = new Solution1();
    int n = solution.longestValidParentheses(s);
    System.out.println(n);
  }

  public static void main(String[] args) {
    test("(()"); // 2
    test(")()())"); // 4
    test("()(()"); // 2
    test("()(())"); // 6
  }
}