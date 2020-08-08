package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/8/9 00:08
 */
public class Solution2 {
  
  public boolean canConvertString(String s, String t, int k) {
    if (s.length() != t.length()) return false;
    int[] count = new int[26];
    for (int i = 0; i < s.length(); i++) {
      char c1 = s.charAt(i), c2 = t.charAt(i);
      int diff = (c2 - c1 + 26) % 26;
      count[diff]++;
    }
    int k_max = 0;
    for (int i = 1; i < 26; i++) {
      k_max = Math.max(k_max, (count[i] - 1) * 26 + i);
    }
    return k >= k_max;
  }
  
  private static void test(String s, String t, int k) {
    Solution2 solution = new Solution2();
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
