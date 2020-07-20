package com.ooooo;

class Solution1 {
  
  public int maxProduct(int[] nums) {
    int ans = 0;
    for (int i = 0; i < nums.length; i++) {
      for (int j = i + 1; j < nums.length; j++) {
        ans = Math.max(ans, (nums[i] - 1) * (nums[j] - 1));
      }
    }
    return ans;
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int i = solution.maxProduct(nums);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{3, 4, 5, 2}); // 12
  }
}