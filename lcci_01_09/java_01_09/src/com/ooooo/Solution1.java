package com.ooooo;

import java.util.HashMap;
import java.util.Map;

/**
 * @author leizhijie
 * @since 2020/5/3 10:36
 */
public class Solution1 {

  public boolean isFlipedString(String s1, String s2) {
    if (s1.isEmpty() && s2.isEmpty()) return true;
    Map<Character, Integer> s_map = new HashMap<>();
    for (int i = 0; i < s1.length(); i++) {
      s_map.put(s1.charAt(i), s_map.getOrDefault(s1.charAt(i), 0) + 1);
    }
    for (int i = 0; i < s2.length(); i++) {
      int count = s_map.getOrDefault(s2.charAt(i), 0);
      if (count == 0) return false;
      s_map.put(s2.charAt(i), count - 1);
    }
    return s1.length() == s2.length() && (s2 + s2).indexOf(s1) < s1.length();
  }

  private static void test(String s1, String s2) {
    Solution1 solution = new Solution1();
    System.out.println(solution.isFlipedString(s1, s2));
  }

  public static void main(String[] args) {
    test("aba", "bab");
    test("", "");
    test("waterbottle", "erbottlewat");
    test("aa", "aba");
  }
}
