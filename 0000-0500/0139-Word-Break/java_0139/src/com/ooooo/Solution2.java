package com.ooooo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * @author leizhijie
 * @since 2020/6/27 19:17
 */
public class Solution2 {

  private Set<String> words = new HashSet<>();
  private int min_len = Integer.MAX_VALUE, max_len = Integer.MIN_VALUE;

  public boolean wordBreak(String s, List<String> wordDict) {
    for (String word : wordDict) {
      words.add(word);
      min_len = Math.min(min_len, word.length());
      max_len = Math.max(max_len, word.length());
    }
    boolean[] dp = new boolean[s.length() + 1];
    dp[0] = true;
    for (int i = 0; i < s.length(); i++) {
      for (int j = min_len; j <= max_len; j++) {
        // 要包含当前字符，所以要i+1
        String word = s.substring(Math.max(0, i - j + 1), i + 1);
        dp[i + 1] = words.contains(word) && dp[Math.max(0, i - j + 1)];
        if (dp[i + 1]) break;
      }
    }
    return dp[s.length()];
  }

  private static void test(String s, String[] wordDict) {
    Solution2 solution = new Solution2();
    boolean b = solution.wordBreak(s, new ArrayList<>(Arrays.asList(wordDict)));
    System.out.println(b);
  }

  public static void main(String[] args) {
    test("leetcode", new String[]{"leet", "code"}); // true
    test("applepenapple", new String[]{"apple", "pen"}); // true
    test("catsandog", new String[]{"cats", "dog", "sand", "and", "cat"}); // false
  }
}
