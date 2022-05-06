package com.ooooo;

import java.util.Arrays;
import java.util.Set;
import java.util.stream.Collectors;

class Solution1 {
  
  public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
    int count = 0;
    for (int i : arr1) {
      count++;
      for (int j : arr2) {
        if (Math.abs(i - j) <= d) {
          count--;
          break;
        }
      }
    }
    return count;
  }
  
  private static void test(int[] arr1, int[] arr2, int d) {
    Solution1 solution = new Solution1();
    int i = solution.findTheDistanceValue(arr1, arr2, d);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{4, 5, 8}, new int[]{10, 9, 1, 8}, 2); // 2
    test(new int[]{1, 4, 2, 3}, new int[]{-4, -3, 6, 10, 20, 30}, 3); // 2
  }
}