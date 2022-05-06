package com.ooooo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

/**
 * @author leizhijie
 * @since 2020/5/26 11:16
 */
public class Solution2 {

  public String[] permutation(String S) {
    if (S.length() == 1) return new String[]{S};
    List<String> ans = new ArrayList<>();
    StringBuilder sb = new StringBuilder(S);
    for (int i = 0; i < S.length(); i++) {
      char c = S.charAt(i);
      sb.deleteCharAt(i);
      ans.addAll(
          Arrays.stream(permutation(sb.toString()))
              .map(x -> c + x)
              .collect(Collectors.toList()));
      sb.insert(i, c);
    }
    return ans.toArray(new String[0]);
  }

  private static void test(String s) {
    Solution2 solution = new Solution2();
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
