package com.ooooo;

class Solution1 {
  
  public int dominantIndex(int[] nums) {
    if (nums.length == 0) return -1;
    int a = 0, b = 0, j = -1;
    for (int i = 0; i < nums.length; i++) {
      if (nums[i] > a) {
        b = a;
        a = nums[i];
        j = i;
      } else if (nums[i] > b) {
        b = nums[i];
      }
    }
    return a >= b * 2 ? j : -1;
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int i = solution.dominantIndex(nums);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{3, 6, 1, 0});
  }
}