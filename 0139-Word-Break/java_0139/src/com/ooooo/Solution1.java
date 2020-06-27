package com.ooooo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

class Solution1 {

  private Set<String> words = new HashSet<>();
  private int min_len = Integer.MAX_VALUE, max_len = Integer.MIN_VALUE;
  private Map<Integer, Boolean> memo = new HashMap<>();

  private boolean dfs(String s, int i) {
    if (memo.containsKey(i)) return memo.get(i);
    if (i == s.length()) return true;
    for (int j = min_len; j <= max_len; j++) {
      String word = s.substring(i, Math.min(i + j, s.length()));
      if (words.contains(word) && dfs(s, i + j)) {
        memo.put(i, true);
        return true;
      }
    }
    memo.put(i, false);
    return false;
  }

  public boolean wordBreak(String s, List<String> wordDict) {
    for (String word : wordDict) {
      words.add(word);
      min_len = Math.min(min_len, word.length());
      max_len = Math.max(max_len, word.length());
    }
    return dfs(s, 0);
  }

  private static void test(String s, String[] wordDict) {
    Solution1 solution = new Solution1();
    boolean b = solution.wordBreak(s, new ArrayList<>(Arrays.asList(wordDict)));
    System.out.println(b);
  }

  public static void main(String[] args) {
    test("leetcode", new String[]{"leet", "code"}); // true
    test("applepenapple", new String[]{"apple", "pen"}); // true
    test("catsandog", new String[]{"cats", "dog", "sand", "and", "cat"}); // false
  }
}