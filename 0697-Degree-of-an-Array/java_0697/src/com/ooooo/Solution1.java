package com.ooooo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution1 {
  
  public int findShortestSubArray(int[] nums) {
    Map<Integer, Integer> count_map = new HashMap<>();
    int max_count = 0;
    List<Integer> max_nums = new ArrayList<>();
    for (int num : nums) {
      int count = count_map.getOrDefault(num, 0) + 1;
      if (count > max_count) {
        max_count = count;
        max_nums.clear();
        max_nums.add(num);
      } else if (count == max_count) {
        max_nums.add(num);
      }
      count_map.put(num, count);
    }
    
    int ans = nums.length;
    for (Integer max_num : max_nums) {
      int l = 0, r = nums.length - 1;
      for (; l < nums.length; l++) {
        if (nums[l] == max_num) break;
      }
      for (; r >= 0; r--) {
        if (nums[r] == max_num) break;
      }
      ans = Math.min(ans, r - l + 1);
    }
    return ans;
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int array = solution.findShortestSubArray(nums);
    System.out.println(array);
  }
  
  public static void main(String[] args) {
    test(new int[]{
        1, 2, 2, 3, 1
    }); // 2
    
    test(new int[]{
        1, 2, 2, 3, 1, 4, 2
    }); // 6
  }
}