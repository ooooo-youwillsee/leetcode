package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/6/9 11:56
 */
public class Solution2 {
  
  
  public int titleToNumber(String s) {
    if (s.length() == 0) return 0;
    return titleToNumber(s.substring(0, s.length() - 1)) * 26 + s.charAt(s.length() - 1) - 'A' + 1;
  }
  
  private static void test(String s) {
    Solution2 solution = new Solution2();
    int ans = solution.titleToNumber(s);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    test("A"); // 1
    test("AB"); // 28
    test("ZY"); // 701
  }
  
}
