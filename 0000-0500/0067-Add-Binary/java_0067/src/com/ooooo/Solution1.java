package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/6/23 08:50
 */
public class Solution1 {
  
  public String addBinary(String a, String b) {
    int i = 0, j = 0, len = Math.max(a.length(), b.length());
    StringBuilder sb = new StringBuilder();
    int c = 0;
    while (i < len || j < len) {
      int int_a = i >= a.length() ? 0 : a.charAt(a.length() - 1 - i) - '0';
      int int_b = j >= b.length() ? 0 : b.charAt(b.length() - 1 - j) - '0';
      c += int_a + int_b;
      sb.append(c % 2 == 1 ? '1' : '0');
      c = c >= 2 ? 1 : 0;
      i++;
      j++;
    }
    if (c > 0) sb.append('1');
    return sb.reverse().toString();
  }
  
  private static void test(String a, String b) {
    Solution1 solution = new Solution1();
    String c = solution.addBinary(a, b);
    System.out.println(c);
  }
  
  public static void main(String[] args) {
    test("11", "1"); // 100
    test("1010", "1011"); // 10101
  }
}
