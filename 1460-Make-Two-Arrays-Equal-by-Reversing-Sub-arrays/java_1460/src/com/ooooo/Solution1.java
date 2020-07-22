package com.ooooo;

import java.util.HashMap;
import java.util.Map;

class Solution1 {
  
  public boolean canBeEqual(int[] target, int[] arr) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i : target) {
      map.put(i, map.getOrDefault(i, 0) + 1);
    }
    for (int i : arr) {
      if (map.getOrDefault(i, 0) == 0) return false;
      else map.put(i, map.get(i) - 1);
    }
    return true;
  }
  
  private static void test(int[] target, int[] arr) {
    Solution1 solution = new Solution1();
    boolean b = solution.canBeEqual(target, arr);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 2, 3, 4}, new int[]{2, 4, 1, 3});
    test(new int[]{1, 2, 3, 4}, new int[]{2, 4, 1, 5});
  }
}