package com.ooooo;

/**
 * force
 */
class Solution1 {

  public int threeSumClosest(int[] nums, int target) {
    int diff = Integer.MAX_VALUE, ans = 0;
    for (int i = 0, len = nums.length; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
        for (int k = j + 1; k < len; k++) {
          int sum = nums[i] + nums[j] + nums[k];
          int sub = Math.abs(sum - target);
          if (sub == 0) return sum;
          if (sub < diff) {
            ans = sum;
            diff = sub;
          }
        }
      }
    }
    return ans;
  }

  private static void test(int[] nums, int target) {
    Solution1 solution = new Solution1();
    int num = solution.threeSumClosest(nums, target);
    System.out.println(num);
  }

  public static void main(String[] args) {
    test(new int[]{-1, 2, 1, -4}, 1);
  }
}