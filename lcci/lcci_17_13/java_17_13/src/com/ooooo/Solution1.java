package com.ooooo;

/**
 * 可以使用BK（字符串hash算法） 或者 Trie 来优化
 */
class Solution1 {


  public int respace(String[] dictionary, String sentence) {
    if (dictionary == null || dictionary.length == 0) return sentence.length();
    int n = sentence.length();
    int[] dp = new int[n + 1];
    for (int i = 0; i < n; i++) {
      dp[i + 1] = dp[i] + 1;
      for (String s : dictionary) {
        if (i + 1 < s.length()) continue;
        if (s.equals(sentence.substring(i + 1 - s.length(), i + 1))) {
          dp[i + 1] = Math.min(dp[i + 1], dp[i + 1 - s.length()]);
        }
      }
    }
    return dp[n];
  }

  private static void test(String[] dict, String s) {
    Solution1 solution = new Solution1();
    int i = solution.respace(dict, s);
    System.out.println(i);
  }

  public static void main(String[] args) {
    test(new String[]{"looked", "just", "like", "her", "brother"}, "jesslookedjustliketimherbrother"); // 7
  }

}