package com.ooooo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution1 {
  
  public List<Integer> minSubsequence(int[] nums) {
    Arrays.sort(nums);
    int n = nums.length;
    int[] sums = new int[n + 1];
    for (int i = 0; i < n; i++) {
      sums[i + 1] = sums[i] + nums[i];
    }
    List<Integer> ans = new ArrayList<>();
    for (int i = n - 1; i >= 0; i--) {
      if ((sums[n] - sums[i + 1]) > sums[i + 1]) break;
      else ans.add(nums[i]);
    }
    return ans;
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    List<Integer> list = solution.minSubsequence(nums);
    for (Integer i : list) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[]{
        4, 3, 10, 9, 8
    });
    // 10,9
    
    test(new int[]{
        4, 4, 7, 6, 7
    });
    // 7 7 6
  
    test(new int[]{
        4, 4
    });
    // 4,4
  }
}