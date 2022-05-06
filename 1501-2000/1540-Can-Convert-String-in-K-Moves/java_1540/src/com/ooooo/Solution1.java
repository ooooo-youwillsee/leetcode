package com.ooooo;

/**
 * timeout
 */
class Solution1 {
  
  boolean[] marked;
  
  private boolean check(int i, int k) {
    for (int j = i; j <= k; ) {
      if (!marked[j]) {
        marked[j] = true;
        return true;
      } else {
        j += 26;
      }
    }
    return false;
  }
  
  public boolean canConvertString(String s, String t, int k) {
    if (s.length() != t.length()) return false;
    marked = new boolean[k + 1];
    for (int i = 0; i < s.length(); i++) {
      char c1 = s.charAt(i), c2 = t.charAt(i);
      if (c1 == c2) continue;
      int diff = c1 < c2 ? c2 - c1 : 26 - (c1 - c2);
      if (!check(diff, k)) {
        return false;
      }
    }
    return true;
  }
  
  private static void test(String s, String t, int k) {
    Solution1 solution = new Solution1();
    boolean b = solution.canConvertString(s, t, k);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test("aab", "bbb", 27); // true
    test("atmtxzjkz", "tvbtjhvjd", 35); // false
    test("input", "ouput", 9); // true
    test("abc", "bcd", 10); // false
  }
}