package com.ooooo;

import java.util.HashSet;
import java.util.Set;

class Solution1 {

  private Set<String> ans = new HashSet<>();
  private Set<Integer> marked = new HashSet<>();

  private void dfs(String s, StringBuilder sb) {
    if (sb.length() == s.length()) {
      ans.add(sb.toString());
      return;
    }
    for (int j = 0; j < s.length(); j++) {
      if (marked.contains(j)) continue;
      char c = s.charAt(j);
      marked.add(j);
      sb.append(c);
      dfs(s, sb);
      sb.deleteCharAt(sb.length() - 1);
      marked.remove(j);
    }
  }

  public String[] permutation(String S) {
    dfs(S, new StringBuilder());
    return ans.toArray(new String[0]);
  }

  private static void test(String s) {
    Solution1 solution = new Solution1();
    String[] ans = solution.permutation(s);
    for (String word : ans) {
      System.out.print(word + " ");
    }
    System.out.println();
  }

  public static void main(String[] args) {
    test("qqe");
    test("ab");
  }
}