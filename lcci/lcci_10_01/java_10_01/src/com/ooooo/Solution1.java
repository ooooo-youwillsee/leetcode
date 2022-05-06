package com.ooooo;

import java.util.Arrays;

class Solution1 {
  public void merge(int[] A, int m, int[] B, int n) {
    int size = A.length - 1;
    for (int i = 0; i < n; i++) {
      A[size--] = B[i];
    }
    Arrays.sort(A);
  }

  private static void test(int[] A, int m, int[] B, int n) {
    Solution1 solution = new Solution1();
    solution.merge(A, m, B, n);
    for (int i : A) {
      System.out.print(i + " ");
    }
    System.out.println();
  }

  public static void main(String[] args) {
    test(new int[]{1, 2, 3, 0, 0, 0,}, 3, new int[]{2, 5, 6}, 3);
  }
}