package com.ooooo;

import java.util.Arrays;

/**
 * sort 直接排序
 */
class Solution1 {

  public int kthSmallest(int[][] matrix, int k) {
    int n = matrix.length, p = 0;
    int[] nums = new int[n * n];
    for (int[] ints : matrix) {
      for (int j = 0; j < n; j++) {
        nums[p++] = ints[j];
      }
    }
    Arrays.sort(nums);
    return nums[k - 1];
  }

  private static void test(int[][] matrix, int k) {
    Solution1 solution = new Solution1();
    int n = solution.kthSmallest(matrix, k);
    System.out.println(n);
  }

  public static void main(String[] args) {
    test(new int[][]{
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    }, 8);
  }
}