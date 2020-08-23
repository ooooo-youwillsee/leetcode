package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/8/22 23:07
 */
public class Solution1 {
  
  public int minOperations(int[] nums) {
    int count = 0;
    for (int i = 0; i < nums.length; i++) {
      if (nums[i] % 2 == 1) {
        count++;
        nums[i] -= 1;
      }
    }
    if (count == 0) {
      boolean all_is_0 = true;
      for (int i = 0; i < nums.length; i++) {
        if (nums[i] != 0) all_is_0 = false;
        nums[i] /= 2;
      }
      if (all_is_0) return 0;
      count++;
    }
    return count + minOperations(nums);
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int i = solution.minOperations(nums);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{4, 2, 5}); // 6
    test(new int[]{3, 2, 2, 4}); // 7
    test(new int[]{2, 4, 8, 16}); // 8
  }
}
