package com.ooooo;

import java.util.Arrays;

class Solution1 {
  
  public boolean canMakeArithmeticProgression(int[] arr) {
    Arrays.sort(arr);
    int diff = arr[1] - arr[0];
    for (int i = 2; i < arr.length; i++) {
      if (arr[i] - arr[i - 1] != diff) return false;
    }
    return true;
  }
  
  private static void test(int[] arr) {
    Solution1 solution = new Solution1();
    boolean b = solution.canMakeArithmeticProgression(arr);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test(new int[]{3, 5, 1}); // true
    test(new int[]{1, 2, 4}); // false
  }
}