package com.ooooo;

import java.util.Arrays;

class Solution1 {
  
  private static final String one = "Gold Medal", two = "Silver Medal", three = "Bronze Medal";
  
  public String[] findRelativeRanks(int[] nums) {
    int m = nums.length;
    String[] ranks = new String[m];
    int[] tmp = Arrays.copyOf(nums, m);
    Arrays.sort(tmp);
    for (int i = 0; i < m; i++) {
      int k = Arrays.binarySearch(tmp, nums[i]);
      if (k == m - 1) {
        ranks[i] = one;
      } else if (k == m - 2) {
        ranks[i] = two;
      } else if (k == m - 3) {
        ranks[i] = three;
      } else {
        ranks[i] = String.valueOf(m - k);
      }
    }
    return ranks;
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    String[] relativeRanks = solution.findRelativeRanks(nums);
    System.out.println(String.join(",", relativeRanks));
  }
  
  public static void main(String[] args) {
    test(new int[]{5, 4, 3, 2, 1}); // ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
    test(new int[]{10, 3, 8, 9, 4}); // ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
  }
}