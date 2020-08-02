package com.ooooo;

import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

class Solution1 {
  
  public int findLucky(int[] arr) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i : arr) {
      map.put(i, map.getOrDefault(i, 0) + 1);
    }
    int ans = -1;
    for (Entry<Integer, Integer> entry : map.entrySet()) {
      if (entry.getKey().equals(entry.getValue())) {
        ans = Math.max(ans, entry.getKey());
      }
    }
    return ans;
  }
  
  private static void test(int[] arr) {
    Solution1 solution = new Solution1();
    int lucky = solution.findLucky(arr);
    System.out.println(lucky);
  }
  
  public static void main(String[] args) {
    test(new int[]{
        1, 2, 2, 3, 3, 3
    }); // 3
    
    test(new int[]{
        2, 2, 2, 3, 3
    }); // -1
  }
}