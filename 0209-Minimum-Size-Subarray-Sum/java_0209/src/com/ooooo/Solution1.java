package com.ooooo;

class Solution1 {

  public int minSubArrayLen(int s, int[] nums) {
    int l = 0, r = 0, sum = 0, min_len = nums.length +1;
    while (r < nums.length) {
      sum += nums[r++];
      while (sum >= s) {
        min_len = Math.min(min_len, r - l);
        sum -= nums[l++];
      }
    }
    return min_len == nums.length+1 ? 0: min_len;
  }

  private static void test(int s, int[] nums) {
    Solution1 solution = new Solution1();
    int n = solution.minSubArrayLen(s, nums);
    System.out.println(n);
  }

  public static void main(String[] args) {
    test(3, new int[]{1, 1}); // 0
    test(7, new int[]{2, 3, 1, 2, 4, 3}); // 2
  }
}