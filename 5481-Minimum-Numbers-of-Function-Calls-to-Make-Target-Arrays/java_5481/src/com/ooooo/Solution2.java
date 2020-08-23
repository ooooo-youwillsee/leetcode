package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/8/23 17:07
 */
public class Solution2 {
  
  public int minOperations(int[] nums) {
    int count = 0, max = 0;
    for (int num : nums) {
      count += Integer.bitCount(num);
      max = Math.max(max, num);
    }
    while (max > 1) {
      max >>= 1;
      count++;
    }
    return count;
  }
  
  private static void test(int[] nums) {
    Solution2 solution = new Solution2();
    int i = solution.minOperations(nums);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{4, 2, 5}); // 6
    test(new int[]{3, 2, 2, 4}); // 7
    test(new int[]{2, 4, 8, 16}); // 8
  }
}
