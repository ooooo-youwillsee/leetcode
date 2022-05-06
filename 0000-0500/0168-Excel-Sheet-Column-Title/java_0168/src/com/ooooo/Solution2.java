package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/6/11 12:04
 */
public class Solution2 {
  
  public String convertToTitle(int n) {
    StringBuilder sb = new StringBuilder();
    while (n > 0) {
      n--;
      sb.append((char) (n % 26 + 'A'));
      n /= 26;
    }
    return sb.reverse().toString();
  }
  
  private static void test(int n) {
    Solution1 solution = new Solution1();
    String ans = solution.convertToTitle(n);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    // A * 26 + Z * 1 = 52
    test(52); // AZ
    test(1); // A
    test(28); // AB
    test(701); // ZY
  }
  
}
