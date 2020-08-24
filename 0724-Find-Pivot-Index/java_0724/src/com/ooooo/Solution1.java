package com.ooooo;

class Solution1 {
  
  public int pivotIndex(int[] nums) {
    int[] sum = new int[nums.length];
    for (int i = 0; i < nums.length; i++) {
      if (i == 0) sum[i] = nums[i];
      else sum[i] = sum[i - 1] + nums[i];
    }
    
    for (int i = 0; i < nums.length; i++) {
      int left_sum = sum[i] - nums[i];
      int right_sum = sum[nums.length - 1] - sum[i];
      if (left_sum == right_sum) return i;
    }
    return -1;
  }
  
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int i = solution.pivotIndex(nums);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 7, 3, 6, 5, 6}); // 3
  }
}