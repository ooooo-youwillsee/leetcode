package com.ooooo;

class Solution1 {
  
  private boolean canWin = false;
  
  // 1, 5, 2
  private int dfs(int[] nums, int l, int r, int turn) {
    if (l == r) {
      return nums[l] * turn;
    }
    int left = nums[l] * turn + dfs(nums, l + 1, r, -turn);
    int right = nums[r] * turn + dfs(nums, l, r - 1, -turn);
    return turn == 1 ? Math.max(left, right) : Math.min(left, right);
  }
  
  
  public boolean PredictTheWinner(int[] nums) {
    return dfs(nums, 0, nums.length - 1, 1) >= 0;
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    boolean b = solution.PredictTheWinner(nums);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 5, 2}); // false
    test(new int[]{1, 5, 233, 7}); // true
  }
}