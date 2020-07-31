package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/7/31 15:05
 */
public class Solution2 {
  
  
  public int findComplement(int num) {
    int bit = 0, b = num;
    while (b > 0) {
      b >>= 1;
      bit++;
    }
    return num ^ ((1 << bit) - 1);
  }
  
  private static void test(int num) {
    Solution2 solution = new Solution2();
    int complement = solution.findComplement(num);
    System.out.println(complement);
  }
  
  public static void main(String[] args) {
    test(5); // 2
    test(1); // 0
    System.out.println(~5);
  }
}
