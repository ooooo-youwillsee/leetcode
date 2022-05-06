package com.ooooo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

class Solution1 {
  
  public int[] relativeSortArray(int[] arr1, int[] arr2) {
    Set<Integer> set = new HashSet<>(arr2.length);
    for (int i : arr2) {
      set.add(i);
    }
    Map<Integer, Integer> map = new HashMap<>();
    List<Integer> others = new ArrayList<>();
    for (int i : arr1) {
      if (set.contains(i)) map.put(i, map.getOrDefault(i, 0) + 1);
      else others.add(i);
    }
    int[] ans = new int[arr1.length];
    int k = 0;
    for (int value : arr2) {
      int count = map.get(value);
      for (int j = 0; j < count; j++) {
        ans[k++] = value;
      }
    }
    others.sort(Integer::compareTo);
    for (Integer other : others) {
      ans[k++] = other;
    }
    return ans;
  }
  
  private static void test(int[] arr1, int[] arr2) {
    Solution1 solution = new Solution1();
    int[] ints = solution.relativeSortArray(arr1, arr2);
    for (int i : ints) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[]{2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19}, new int[]{2, 1, 4, 3, 9, 6});
  }
}