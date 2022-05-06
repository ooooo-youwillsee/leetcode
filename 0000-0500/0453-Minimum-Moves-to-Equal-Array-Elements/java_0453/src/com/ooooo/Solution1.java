package com.ooooo;

import java.util.Arrays;

class Solution1 {
  
  public int minMoves(int[] nums) {
    Arrays.sort(nums);
    int sum = 0;
    for (int i = nums.length - 1; i >= 0; i--) {
      sum += nums[i] - nums[0];
    }
    return sum;
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int i = solution.minMoves(nums);
    System.out.println(i);
  }
  
  
  public static void main(String[] args) {
    test(new int[]{1, 2, 3});
    test(new int[]{1, 1, 2147483647});
  }
}