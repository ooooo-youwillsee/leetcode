package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/6/13 11:04
 */
public class Solution2 {
  
  public boolean isPowerOfFour(int num) {
    //  (num & (num - 1)) == 0 保证只有一位
    return num > 0 && (num & (num - 1)) == 0 && (num & 0xaaaaaaaa) == 0;
  }
  
  private static void test(int n) {
    Solution2 solution = new Solution2();
    boolean ans = solution.isPowerOfFour(n);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    test(1);
    test(16);
    test(5);
  }
}
