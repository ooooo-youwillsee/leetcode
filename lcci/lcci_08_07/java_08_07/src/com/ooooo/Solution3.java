package com.ooooo;

import java.util.ArrayList;
import java.util.List;

/**
 * @author leizhijie
 * @since 2020/5/26 17:56
 */
public class Solution3 {

  private void swap(StringBuilder sb, int i, int j) {
    char c = sb.charAt(i);
    sb.setCharAt(i, sb.charAt(j));
    sb.setCharAt(j, c);
  }

  private void dfs(StringBuilder sb, int i) {
    if (i == sb.length()) {
      ans.add(sb.toString());
      return;
    }
    for (int j = i; j < sb.length(); j++) {
      swap(sb, i, j);
      dfs(sb, i + 1);
      swap(sb, i, j);
    }
  }

  private List<String> ans = new ArrayList<>();

  public String[] permutation(String S) {
    dfs(new StringBuilder(S), 0);
    return ans.toArray(new String[0]);
  }

  private static void test(String s) {
    Solution3 solution = new Solution3();
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
