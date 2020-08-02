package com.ooooo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution1 {
  
  public List<List<Integer>> minimumAbsDifference(int[] arr) {
    Arrays.sort(arr);
    int min_diff = Integer.MAX_VALUE;
    for (int i = 0; i < arr.length - 1; i++) {
      min_diff = Math.min(arr[i + 1] - arr[i], min_diff);
    }
    List<List<Integer>> ans = new ArrayList<>();
    for (int i = 0; i < arr.length - 1; i++) {
      if (arr[i + 1] - arr[i] == min_diff) {
        List<Integer> pair = new ArrayList<>();
        pair.add(arr[i]);
        pair.add(arr[i + 1]);
        ans.add(pair);
      }
    }
    return ans;
  }
  
  private static void test(int[] arr) {
    Solution1 solution = new Solution1();
    List<List<Integer>> lists = solution.minimumAbsDifference(arr);
    for (List<Integer> list : lists) {
      System.out.print(String.format("(%d, %d) ", list.get(0), list.get(1)));
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[]{
        4, 2, 1, 3
    });
  }
}