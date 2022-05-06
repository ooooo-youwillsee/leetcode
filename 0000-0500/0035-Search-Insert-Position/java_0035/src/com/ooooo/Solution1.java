package com.ooooo;

class Solution1 {
  
  public int searchInsert(int[] nums, int target) {
    int l = 0, r = nums.length;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
  }
  
  private static void test(int[] nums, int target) {
    Solution1 solution = new Solution1();
    int i = solution.searchInsert(nums, target);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 3, 5, 6}, 5); // 2
    test(new int[]{1, 3, 5, 6}, 2); // 1
    test(new int[]{1, 3, 5, 6}, 7); // 4
    test(new int[]{1, 3, 5, 6}, 0); // 0
  }
}