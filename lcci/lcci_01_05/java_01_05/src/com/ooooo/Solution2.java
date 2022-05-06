package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/4/28 19:22
 *
 * 相等的长度，只能replace
 */
public class Solution2 {

  public boolean oneEditAway(String first, String second) {
    if (Math.abs(first.length() - second.length()) > 1) return false;
    int i = 0, j = 0;
    boolean repalce = false;
    if (first.length() > second.length()) {
      String tmp = first;
      first = second;
      second = tmp;
    }
    while (i < first.length() && j < second.length()) {
      char first_c = first.charAt(i);
      char second_c = second.charAt(j);
      if (first_c == second_c) {
        i++;
        j++;
      } else {
        if (repalce) return false;
        repalce = true;
        if (first.length() == second.length()) i++;
        j++;
      }
    }
    return true;
  }

  private static void test(String s1, String s2) {
    Solution1 solution = new Solution1();
    System.out.println(solution.oneEditAway(s1, s2));
  }

  public static void main(String[] args) {
    test("pale", "ple");
    test("abc", "ab");
    test("abc", "abcd");
    test("pales", "pal");
  }
}
