package com.ooooo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution1 {
  
  public int[] intersect(int[] nums1, int[] nums2) {
    Map<Integer, Integer> count_map = new HashMap<>();
    for (int i : nums1) {
      count_map.put(i, count_map.getOrDefault(i, 0) + 1);
    }
    List<Integer> ans = new ArrayList<>(nums2.length);
    for (int i : nums2) {
      if (count_map.getOrDefault(i,0).compareTo(0) > 0) {
        ans.add(i);
        count_map.put(i, count_map.get(i) - 1);
      }
    }
    int[] nums = new int[ans.size()];
    for (int i = 0; i < ans.size(); i++) {
      nums[i] = ans.get(i);
    }
    return nums;
  }
  
  private static void test(int[] nums1, int[] nums2) {
    Solution1 solution = new Solution1();
    int[] intersect = solution.intersect(nums1, nums2);
    for (int i : intersect) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 2, 2, 1}, new int[]{2, 2});
    test(new int[]{4, 9, 5}, new int[]{9, 4, 9, 8, 4});
  }
}