package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/6/19 09:13
 */
public class Solution2 {
  
  public boolean isPalindrome(String s) {
    if (s == null || s.length() == 0) return true;
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < s.length(); i++) {
      char c = s.charAt(i);
      if (Character.isDigit(c) || Character.isAlphabetic(c)) sb.append(Character.toLowerCase(c));
    }
    return sb.toString().equals(sb.reverse().toString());
  }
  
  private static void test(String s) {
    Solution1 solution = new Solution1();
    boolean b = solution.isPalindrome(s);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test("A man, a plan, a canal: Panama"); // true
    test("race a car"); // false
  }
}
