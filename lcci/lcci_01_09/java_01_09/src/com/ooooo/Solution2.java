package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/5/3 10:54
 */
public class Solution2 {


  public boolean isFlipedString(String s1, String s2) {
    if (s1.isEmpty() && s2.isEmpty()) return true;
    int i = (s2 + s2).indexOf(s1);
    return s1.length() == s2.length() && i < s1.length() && i >= 0;
  }

  private static void test(String s1, String s2) {
    Solution2 solution = new Solution2();
    System.out.println(solution.isFlipedString(s1, s2));
  }

  public static void main(String[] args) {
    test("aba", "bab");
    test("", "");
    System.out.println("".indexOf(""));
    test("waterbottle", "erbottlewat");
    test("aa", "aba");
  }
}
