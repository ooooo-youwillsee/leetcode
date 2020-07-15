package com.ooooo;

class Solution1 {
  
  public int[] runningSum(int[] nums) {
    int[] sum = new int[nums.length];
    for (int i = 0; i < nums.length; i++) {
      if (i == 0) sum[i] = nums[i];
      else sum[i] = sum[i - 1] + nums[i];
    }
    return sum;
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int[] ints = solution.runningSum(nums);
    for (int i : ints) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
  
  
  public static void main(String[] args) {
    test(new int[]{1, 2, 3, 4});
  }
  
}