package com.ooooo;

import java.util.HashSet;
import java.util.Set;

class Solution1 {

  public int firstMissingPositive(int[] nums) {
    Set<Integer> set = new HashSet<>();
    for (int num : nums) {
      set.add(num);
    }
    for (int i = 1; i <= nums.length + 1; i++) {
      if (set.contains(i)) continue;
      return i;
    }
    return -1;
  }

  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int n = solution.firstMissingPositive(nums);
    System.out.println(n);
  }

  public static void main(String[] args) {
    test(new int[]{1, 2, 0});  // 3
    test(new int[]{3, 4, -1, 1}); // 2
    test(new int[]{7, 8, 9, 11, 12}); // 1
  }


}