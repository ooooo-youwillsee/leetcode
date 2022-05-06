package com.ooooo;

import java.util.ArrayList;
import java.util.List;

class Solution1 {
  
  
  private void dfs(int l, int r, StringBuilder s) {
    if (l < 0 || r < 0) return;
    if (l == 0 && r == 0) {
      ans.add(s.toString());
      return;
    }
    if (l != r) {
      s.append(')');
      dfs(l, r - 1, s);
      s.deleteCharAt(s.length() - 1);
    }
    s.append('(');
    dfs(l - 1, r, s);
    s.deleteCharAt(s.length() - 1);
  }
  
  private List<String> ans = new ArrayList<>();
  
  public List<String> generateParenthesis(int n) {
    dfs(n, n, new StringBuilder());
    return ans;
  }
  
  private static void test(int n) {
    Solution1 solution = new Solution1();
    List<String> res = solution.generateParenthesis(n);
    for (String s : res) {
      System.out.print(s + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(3);
  }
}