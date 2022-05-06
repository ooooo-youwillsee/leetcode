package com.ooooo;

class Solution1 {
  
  public double findMaxAverage(int[] nums, int k) {
    double sum = 0, ans = Integer.MIN_VALUE;
    for (int i = 0; i < nums.length; i++) {
      sum += nums[i];
      if (i >= k - 1) {
        ans = Math.max(ans, sum / k);
        sum -= nums[i - k + 1];
      }
    }
    return ans;
  }
  
  
  private static void test(int[] nums, int k) {
    Solution1 solution = new Solution1();
    double maxAverage = solution.findMaxAverage(nums, k);
    System.out.println(maxAverage);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 12, -5, -6, 50, 3}, 4); // 12.75
  }
}