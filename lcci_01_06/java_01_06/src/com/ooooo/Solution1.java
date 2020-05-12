package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/4/30 21:23
 */
public class Solution1 {


  public String compressString(String S) {
    if (S.isEmpty()) return "";
    StringBuilder sb = new StringBuilder();
    int count = 1;
    for (int i = 1; i < S.length(); i++) {
      if (S.charAt(i) == S.charAt(i - 1)) count++;
      else {
        sb.append(S.charAt(i - 1)).append(count);
        count = 1;
      }
    }
    sb.append(S.charAt(S.length() - 1)).append(count);
    String ans = sb.toString();
    return ans.length() >= S.length() ? S : ans;
  }

  private static void test(String s) {
    Solution1 solution = new Solution1();
    System.out.println(solution.compressString(s));
  }

  public static void main(String[] args) {
    test("aabcccccaaa");
    test("");
    test("a");
    test("ab");
    test("aa");
    test("abbccd");
  }
}
