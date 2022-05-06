package com.ooooo;

public class Solution2 {

  public void merge(int[] A, int m, int[] B, int n) {
    int[] tmp = new int[m];
    if (m >= 0) System.arraycopy(A, 0, tmp, 0, m);
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
      if (tmp[i] <= B[j]) A[k++] = tmp[i++];
      else A[k++] = B[j++];
    }
    while (i < m) {
      A[k++] = tmp[i++];
    }
    while (j < n) {
      A[k++] = B[j++];
    }
  }

  private static void test(int[] A, int m, int[] B, int n) {
    Solution2 solution = new Solution2();
    solution.merge(A, m, B, n);
    for (int i : A) {
      System.out.print(i + " ");
    }
    System.out.println();
  }

  public static void main(String[] args) {
    test(new int[]{4, 5, 6, 0, 0, 0}, 3, new int[]{1, 2, 3}, 3);
    test(new int[]{1, 2, 3, 0, 0, 0,}, 3, new int[]{2, 5, 6}, 3);
    test(new int[]{2, 2, 3, 0, 0, 0,}, 3, new int[]{1, 5, 6}, 3);
  }
}
