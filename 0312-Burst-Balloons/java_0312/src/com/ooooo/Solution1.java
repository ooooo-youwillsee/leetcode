package com.ooooo;

/**
 * recursive timeout
 */
class Solution1 {
  
  private int[] genArrExcludeI(int[] nums, int i) {
    if (nums.length == 1) return new int[0];
    int[] ans = new int[nums.length - 1];
    for (int j = 0, k = 0; j < nums.length; j++) {
      if (j != i) ans[k++] = nums[j];
    }
    return ans;
  }
  
  public int maxCoins(int[] nums) {
    int ans = 0;
    for (int i = 0; i < nums.length; i++) {
      int p = (i - 1 < 0 ? 1 : nums[i - 1]) * nums[i] * (i + 1 >= nums.length ? 1 : nums[i + 1]);
      ans = Math.max(ans, p + maxCoins(genArrExcludeI(nums, i)));
    }
    return ans;
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int i = solution.maxCoins(nums);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{3, 1, 5, 8}); // 167
  }
}