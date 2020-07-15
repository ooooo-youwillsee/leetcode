package com.ooooo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

class Solution1 {
  
  public int numIdenticalPairs(int[] nums) {
    Map<Integer, List<Integer>> index_map = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
      List<Integer> indexes = index_map.getOrDefault(nums[i], new ArrayList<>());
      indexes.add(i);
      index_map.put(nums[i], indexes);
    }
    
    int count = 0;
    for (Entry<Integer, List<Integer>> entry : index_map.entrySet()) {
      List<Integer> indexes = entry.getValue();
      if (indexes.size() > 1) {
        count += indexes.size() * (indexes.size() - 1) / 2;
      }
    }
    return count;
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int i = solution.numIdenticalPairs(nums);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 2, 3, 1, 1, 3});
    test(new int[]{1, 1, 1, 1});
    test(new int[]{1, 2, 3});
  }
}