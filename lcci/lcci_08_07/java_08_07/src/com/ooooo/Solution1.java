package com.ooooo;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution1 {

  private void dfs(String s, StringBuilder sb) {
    if (set.size() == s.length()) {
      ans.add(sb.toString());
      return;
    }
    for (int i = 0; i < s.length(); i++) {
      char c = s.charAt(i);
      if (set.contains(c)) continue;
      set.add(c);
      sb.append(c);
      dfs(s, sb);
      set.remove(c);
      sb.deleteCharAt(sb.length() - 1);
    }
  }

  private List<String> ans = new ArrayList<>();
  private Set<Character> set = new HashSet<>();

  public String[] permutation(String S) {
    dfs(S, new StringBuilder());
    return ans.toArray(new String[0]);
  }

  private static void test(String s) {
    Solution1 solution = new Solution1();
    String[] ans = solution.permutation(s);
    for (String ss : ans) {
      System.out.print(ss + " ");
    }
    System.out.println();
  }

  public static void main(String[] args) {
    test("qwe");
    test("ab");
  }
}