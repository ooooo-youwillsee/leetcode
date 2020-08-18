package com.ooooo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author leizhijie
 * @since 2020/8/18 21:10
 */
public class Solution2 {
  
  
  public int findShortestSubArray(int[] nums) {
    Map<Integer, List<Integer>> count_map = new HashMap<>();
    int max_count = 0, ans = nums.length;
    for (int i = 0; i < nums.length; i++) {
      List<Integer> indexes = count_map.computeIfAbsent(nums[i], k -> new ArrayList<>());
      indexes.add(i);
      int count = indexes.size();
      if (count > max_count) {
        ans = indexes.get(count - 1) - indexes.get(0) + 1;
        max_count = count;
      } else if (count == max_count) {
        ans = Math.min(ans, indexes.get(count - 1) - indexes.get(0) + 1);
      }
    }
    return ans;
  }
  
  private static void test(int[] nums) {
    Solution2 solution = new Solution2();
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
