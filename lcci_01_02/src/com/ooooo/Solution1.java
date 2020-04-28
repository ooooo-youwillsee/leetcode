package com.ooooo;

import java.util.HashMap;
import java.util.Map;

/**
 * @author leizhijie
 * @since 2020/4/28 17:12
 */
public class Solution1 {


  public boolean CheckPermutation(String s1, String s2) {
    Map<Character, Integer> map = new HashMap<>();
    for (int i = 0; i < s1.length(); i++) {
      map.put(s1.charAt(i), map.getOrDefault(s1.charAt(i), 0) + 1);
    }
    for (int i = 0; i < s2.length(); i++) {
      char c = s2.charAt(i);
      if (map.getOrDefault(c, 0) < 1) {
        return false;
      }
      map.put(c, map.get(c) - 1);
    }
    return true;
  }

  private static void test(String s1, String s2) {
    Solution1 solution = new Solution1();
    System.out.println(solution.CheckPermutation(s1, s2));
  }

  public static void main(String[] args) {
    test("abc", "bca");
    test("abc", "bad");
  }
}
