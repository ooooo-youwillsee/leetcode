package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/4/28 17:39
 */
public class Solution1 {

  private boolean dfs(int first_i, int second_i) {
    if (first_i == first.length() && (second_i == second.length() || !replace)) return true;
    if (first_i == first.length() || second_i == second.length()) return false;
    char first_c = first.charAt(first_i);
    char second_c = second.charAt(second_i);
    if (first_c == second_c) return dfs(first_i + 1, second_i + 1);
    if (replace) return false;
    replace = true;
    return dfs(first_i, second_i + 1) || dfs(first_i + 1, second_i + 1);
  }

  String first, second;
  boolean replace;

  public boolean oneEditAway(String first, String second) {
    if (Math.abs(first.length() - second.length()) > 1) return false;
    if (first.length() < second.length()) {
      this.first = first;
      this.second = second;
    } else {
      this.first = second;
      this.second = first;
    }
    this.replace = false;
    return dfs(0, 0);
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
