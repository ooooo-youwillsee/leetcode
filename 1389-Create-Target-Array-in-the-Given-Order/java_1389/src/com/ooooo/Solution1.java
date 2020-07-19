package com.ooooo;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.stream.Collectors;

class Solution1 {
  
  public int[] createTargetArray(int[] nums, int[] index) {
    List<Integer> list = new LinkedList<>();
    for (int i = 0; i < nums.length; i++) {
      list.add(index[i], nums[i]);
    }
    return list.stream().mapToInt(Integer::intValue).toArray();
  }
  
  private static void test(int[] nums, int[] index) {
    Solution1 solution = new Solution1();
    int[] targetArray = solution.createTargetArray(nums, index);
    for (int i : targetArray) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[]{0, 1, 2, 3, 4}, new int[]{0, 1, 2, 2, 1}); // 0,4,1,3,2
  }
}