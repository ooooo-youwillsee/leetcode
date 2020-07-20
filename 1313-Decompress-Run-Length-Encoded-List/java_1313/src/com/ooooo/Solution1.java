package com.ooooo;

import java.util.ArrayList;
import java.util.List;

class Solution1 {
  
  public int[] decompressRLElist(int[] nums) {
    List<Integer> ans = new ArrayList<>();
    for (int i = 0; i < nums.length; i+=2) {
      int freq = nums[i];
      int num = nums[i+1];
      for (int j = 0; j < freq; j++) {
        ans.add(num);
      }
    }
    return ans.stream().mapToInt(Integer::intValue).toArray();
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int[] ans = solution.decompressRLElist(nums);
    for (int i : ans) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 2, 3, 4}); // 2,4,4,4
  }
}