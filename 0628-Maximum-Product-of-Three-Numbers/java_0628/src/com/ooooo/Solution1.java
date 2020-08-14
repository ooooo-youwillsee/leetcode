package com.ooooo;

import java.util.Arrays;

class Solution1 {
  
  public int maximumProduct(int[] nums) {
    Arrays.sort(nums);
    int n = nums.length;
    return Math.max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
  }
  
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int i = solution.maximumProduct(nums);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 2, 3, 4});
    test(new int[]{1, 2, 3, 4, 5});
  }
}