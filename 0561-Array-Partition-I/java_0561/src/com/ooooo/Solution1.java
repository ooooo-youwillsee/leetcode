package com.ooooo;

import java.util.Arrays;

class Solution1 {
  
  public int arrayPairSum(int[] nums) {
    Arrays.sort(nums);
    int sum = 0;
    for (int i = 0; i < nums.length; i += 2) {
      sum += Math.min(nums[i], nums[i + 1]);
    }
    return sum;
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int i = solution.arrayPairSum(nums);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{
        1, 4, 3, 2
    });
  }
  
}