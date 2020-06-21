package com.ooooo;

import java.util.HashMap;
import java.util.Map;

class Solution1 {
  
  private Map<String, Boolean> cache = new HashMap<>();
  
  private boolean isMatch(String s, int i, String p, int j) {
    String key = i + String.valueOf(j);
    if (cache.containsKey(key)) return cache.get(key);
    boolean match = false;
    if (i >= s.length() && j >= p.length()) return true;
    if (j >= p.length()) return false;
    if (i < s.length() && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '?')) {
      match = match || isMatch(s, i + 1, p, j + 1);
    } else if (p.charAt(j) == '*') {
      // s 已经到尾部了，*只能跳过了
      if (i == s.length()) return isMatch(s, i, p, j + 1);
      match = match || isMatch(s, i + 1, p, j + 1) || isMatch(s, i + 1, p, j) || isMatch(s, i, p, j + 1);
    }
    cache.put(key, match);
    return match;
  }
  
  public boolean isMatch(String s, String p) {
    return isMatch(s, 0, p, 0);
  }
  
  private static void test(String s, String p) {
    Solution1 solution = new Solution1();
    boolean b = solution.isMatch(s, p);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test("", "?"); // false
    test("", "*"); // true
    test("adceb", "*a*b"); // true
    test("aa", "*"); // true
    test("aa", "a"); // false
    test("cb", "?a"); // false
  }
}