package com.ooooo;

import java.util.HashMap;
import java.util.Map;

class Solution1 {
  
  public int findSpecialInteger(int[] arr) {
    Map<Integer, Integer> count_map = new HashMap<>();
    for (int i : arr) {
      count_map.put(i, count_map.getOrDefault(i, 0) + 1);
      if (4 * count_map.get(i) > arr.length) {
        return i;
      }
    }
    return -1;
  }
  
  private static void test(int[] arr) {
    Solution1 solution = new Solution1();
    int i = solution.findSpecialInteger(arr);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{
        1, 2, 2, 6, 6, 6, 6, 7, 10
    }); // 6
  }
}