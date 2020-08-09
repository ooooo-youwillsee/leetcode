package com.ooooo;

class Solution1 {
  
  public String makeGood(String s) {
    StringBuilder sb = new StringBuilder(s);
    while (true) {
      int size = sb.length();
      for (int i = 0; i < sb.length() - 1; i++) {
        if (Math.abs(sb.charAt(i) - sb.charAt(i + 1)) == 32) {
          sb.delete(i, i + 2);
          break;
        }
      }
      // 长度没有发生改变，说明没有可删除的字符了
      if (size == sb.length()) break;
    }
    return sb.toString();
  }
  
  private static void test(String s) {
    Solution1 solution = new Solution1();
    String s1 = solution.makeGood(s);
    System.out.println(s1);
  }
  
  public static void main(String[] args) {
    test("qFxXfQo");
    test("abBAcC");
    test("leEeetcode");
    test("cM");
  }
}