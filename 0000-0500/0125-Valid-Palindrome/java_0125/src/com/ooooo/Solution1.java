package com.ooooo;

class Solution1 {
  
  private boolean isDigitOrLetter(char c) {
    return Character.isDigit(c) || Character.isAlphabetic(c);
  }
  
  public boolean isPalindrome(String s) {
    if (s == null || s.length() == 0) return true;
    int i = 0, j = s.length() - 1;
    while (i < j) {
      while (i < j && !isDigitOrLetter(s.charAt(i))) {
        i++;
      }
      while (i < j && !isDigitOrLetter(s.charAt(j))) {
        j--;
      }
      if (i >= j) break;
      if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j))) return false;
      i++;
      j--;
    }
    return true;
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