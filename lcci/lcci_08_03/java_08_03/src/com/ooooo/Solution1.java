package com.ooooo;

class Solution1 {

  public int findMagicIndex(int[] nums) {
    for (int i = 0; i < nums.length; i++) {
      if (nums[i] == i) return i;
    }
    return -1;
  }

  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int ans = solution.findMagicIndex(nums);
    System.out.println(ans);
  }

  public static void main(String[] args) {
    test(new int[]{0, 2, 3, 4, 5});
    test(new int[]{1, 1, 1});
  }
}