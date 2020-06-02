package com.ooooo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;


/**
 *  qqe
 *  分析 ->
 *  q    q    e
 * q e  q e  q q
 * e q  e q  q q
 */
public class Solution2 {

  private List<String> ans = new ArrayList<>();
  private Set<Integer> marked = new HashSet<>();

  private void dfs(char[] s, StringBuilder sb) {
    if (sb.length() == s.length) {
      ans.add(sb.toString());
      return;
    }
    for (int j = 0; j < s.length; j++) {
      if (marked.contains(j) || (j > 0 && s[j] == s[j - 1] && !marked.contains(j - 1))) continue;
      char c = s[j];
      marked.add(j);
      sb.append(c);
      dfs(s, sb);
      sb.deleteCharAt(sb.length() - 1);
      marked.remove(j);
    }
  }

  public String[] permutation(String S) {
    char[] chars = S.toCharArray();
    Arrays.sort(chars);
    dfs(chars, new StringBuilder());
    return ans.toArray(new String[0]);
  }

  private static void test(String s) {
    Solution2 solution = new Solution2();
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
