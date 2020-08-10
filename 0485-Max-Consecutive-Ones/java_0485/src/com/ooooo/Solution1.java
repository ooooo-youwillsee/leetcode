package com.ooooo;

class Solution1 {
  
  public int findMaxConsecutiveOnes(int[] nums) {
    int count = 0, ans = 0;
    for (int j = 0; j < nums.length; j++) {
      if (nums[j] == 1) {
        if ((j == 0 || nums[j - 1] == 0)) count = 1;
        if (j + 1 < nums.length && nums[j] == nums[j + 1]) {
          count++;
        }
      }
      ans = Math.max(ans, count);
    }
    return ans;
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int i = solution.findMaxConsecutiveOnes(nums);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 0, 1, 1, 0, 1}); // 2
    test(new int[]{1, 1, 0, 1, 1, 1}); // 3
    test(new int[]{0, 1, 1, 1, 1, 1}); // 5
    test(new int[]{0, 0, 0}); // 0
    test(new int[]{0, 0, 1}); // 1
    test(new int[]{0, 1, 1}); // 2
    test(new int[]{1}); // 1
    test(new int[]{0}); // 0
    test(new int[]{}); // 0
  }
}