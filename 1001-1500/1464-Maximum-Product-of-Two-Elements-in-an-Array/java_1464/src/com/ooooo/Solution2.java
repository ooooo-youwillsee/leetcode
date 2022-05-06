package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/7/20 18:18
 */
public class Solution2 {
  
  public int maxProduct(int[] nums) {
    // a 表示第一大的值， b 表示第二大的值
    int a = 0, b = 0;
    for (int c : nums) {
      if (c >= a) {
        b = a;
        a = c;
      } else if (c >= b) {
        b = c;
      }
    }
    return (a - 1) * (b - 1);
  }
  
  private static void test(int[] nums) {
    Solution2 solution = new Solution2();
    int i = solution.maxProduct(nums);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{3, 4, 5, 2}); // 12
    test(new int[]{1, 5, 4, 5}); // 16
  }
}
