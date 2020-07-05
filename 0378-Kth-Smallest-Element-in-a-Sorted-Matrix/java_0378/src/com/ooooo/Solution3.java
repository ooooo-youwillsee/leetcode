package com.ooooo;

import java.util.Arrays;

/**
 * @author leizhijie
 * @since 2020/7/5 18:17
 */
public class Solution3 {

  private int count(int[][] matrix, int num) {
    int c = 0, i = matrix.length - 1, j = 0;
    while (i >= 0 && j < matrix.length) {
      if (matrix[i][j] <= num) {
        c += i + 1;
        j++;
      } else {
        i--;
      }
    }
    return c;
  }

  public int kthSmallest(int[][] matrix, int k) {
    int n = matrix.length;
    int l = matrix[0][0], r = matrix[n - 1][n - 1];
    while (l < r) {
      int mid = l + (r - l) / 2;
      int c = count(matrix, mid);
      // 如果数量不少于 k，那么说明最终答案 x 不大于 mid
      if (c >= k) r = mid;
      else l = mid + 1;
    }
    return l;
  }

  private static void test(int[][] matrix, int k) {
    Solution3 solution = new Solution3();
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
