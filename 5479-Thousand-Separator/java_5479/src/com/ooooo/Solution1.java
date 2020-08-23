package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/8/22 22:42
 */
public class Solution1 {
  
  public String thousandSeparator(int n) {
    if (n == 0) return "0";
    StringBuilder sb = new StringBuilder();
    int count = 0;
    while (n > 0) {
      count++;
      sb.append(n % 10);
      n /= 10;
      if (count == 3 && n != 0) {
        sb.append(".");
        count = 0;
      }
    }
    return sb.reverse().toString();
  }
  
  private static void test(int n) {
    Solution1 solution = new Solution1();
    String s = solution.thousandSeparator(n);
    System.out.println(s);
  }
  
  public static void main(String[] args) {
    test(987);
    test(1234);
    test(123456789);
    test(0);
  }
}
