package com.ooooo;

class Solution1 {
  
  public String sortString(String s) {
    int[] letters = new int[26];
    for (int i = 0; i < s.length(); i++) {
      letters[s.charAt(i) - 'a']++;
    }
    
    StringBuilder sb = new StringBuilder();
    while (sb.length() < s.length()) {
      for (int i = 0; i < 26; i++) {
        if (letters[i] > 0) {
          sb.append((char) (97 + i));
          letters[i]--;
        }
      }
      for (int i = 25; i >= 0; i--) {
        if (letters[i] > 0) {
          sb.append((char) (97 + i));
          letters[i]--;
        }
      }
    }
    return sb.toString();
  }
  
  private static void test(String s) {
    Solution1 solution = new Solution1();
    String s1 = solution.sortString(s);
    System.out.println(s1);
  }
  
  public static void main(String[] args) {
    test("aaaabbbbcccc");
    test("rat");
    test("leetcode");
  }
}