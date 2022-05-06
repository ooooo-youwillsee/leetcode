package com.ooooo;

class Solution1 {
  
  
  private boolean check(int[] nums, boolean changed) {
    for (int i = 0; i < nums.length - 1; i++) {
      int a = nums[i], b = nums[i + 1];
      if (a > b) {
        if (changed) return false;
        nums[i + 1] = nums[i] = b;
        if (check(nums, true)) return true;
        nums[i] = nums[i + 1] = a;
        return (check(nums, true));
      }
    }
    return true;
  }
  
  
  public boolean checkPossibility(int[] nums) {
    return check(nums, false);
  }
  
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    boolean b = solution.checkPossibility(nums);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test(new int[]{3, 4, 2, 3}); // false
    test(new int[]{4, 2, 3}); // true
    test(new int[]{2, 3, 3, 2, 4}); // true
    test(new int[]{4, 2, 1}); // false
  }
}