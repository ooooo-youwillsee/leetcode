package com.ooooo;

class Solution1 {
  
  public int titleToNumber(String s) {
    int ans = 0;
    for (int i = s.length() - 1, j = 0; i >= 0; i--, j++) {
      ans += (s.charAt(i) - 'A' + 1) * Math.pow(26, j);
    }
    return ans;
  }
  
  private static void test(String s) {
    Solution1 solution = new Solution1();
    int ans = solution.titleToNumber(s);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    test("A"); // 1
    test("AB"); // 28
    test("ZY"); // 701
  }
}