package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/6/13 13:51
 */
public class Solution2 {
  
  public int getSum(int a, int b) {
    return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
  }
  
  private static void test(int a, int b) {
    Solution1 solution = new Solution1();
    int ans = solution.getSum(a, b);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    test(3, 3);
    test(1, 2);
  }
  
}
