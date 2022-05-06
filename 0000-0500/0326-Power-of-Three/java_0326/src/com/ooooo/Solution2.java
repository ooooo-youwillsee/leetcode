package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/6/13 10:53
 */
public class Solution2 {
  
  
  // 1162261467 是3的19次方， 32位中最大的数
  public boolean isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0;
  }
  
  private static void test(int n) {
    Solution2 solution = new Solution2();
    boolean ans = solution.isPowerOfThree(n);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    test(1);
    test(27);
    test(0);
    test(9);
    test(45);
  }
  
}
