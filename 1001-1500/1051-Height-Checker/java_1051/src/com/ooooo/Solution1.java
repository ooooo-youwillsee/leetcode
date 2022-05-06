package com.ooooo;

import java.util.Arrays;

class Solution1 {
  
  public int heightChecker(int[] heights) {
    int[] tmp = Arrays.copyOf(heights, heights.length);
    Arrays.sort(heights);
    int count = 0;
    for (int i = 0; i < heights.length; i++) {
      if (heights[i] != tmp[i]) count++;
    }
    return count;
  }
  
  private static void test(int[] heights) {
    Solution1 solution = new Solution1();
    int i = solution.heightChecker(heights);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 1, 4, 2, 1, 3});
  }
}