package com.ooooo;

import java.util.Arrays;

class Solution1 {
  
  private int getIndex(int[] nums, int target) {
    int l = 0, r = nums.length;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] > target) {
        r = mid - 1;
      } else if (nums[mid] == target) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
  
  public int[] smallerNumbersThanCurrent(int[] nums) {
    int[] copy = Arrays.copyOf(nums, nums.length);
    Arrays.sort(copy);
    int[] ans = new int[nums.length];
    for (int i = 0, k = 0; i < nums.length; i++) {
      ans[k++] = getIndex(copy, nums[i]);
    }
    return ans;
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int[] ans = solution.smallerNumbersThanCurrent(nums);
    for (int i : ans) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[]{8, 1, 2, 2, 3}); // 4,0,1,1,3
  }
}