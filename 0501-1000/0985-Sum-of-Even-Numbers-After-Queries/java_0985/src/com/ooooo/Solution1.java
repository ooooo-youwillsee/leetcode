package com.ooooo;

import java.util.Arrays;

class Solution1 {
  
  public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
    int sum = Arrays.stream(A).map(a -> a % 2 == 0 ? a : 0).sum();
    int[] ans = new int[A.length];
    for (int i = 0; i < queries.length; i++) {
      int num = queries[i][0], index = queries[i][1];
      if (A[index] % 2 == 0) sum -= A[index];
      A[index] += num;
      if (A[index] % 2 == 0) sum += A[index];
      ans[i] = sum;
    }
    return ans;
  }
  
  
  private static void test(int[] A, int[][] queries) {
    Solution1 solution = new Solution1();
    int[] ints = solution.sumEvenAfterQueries(A, queries);
    for (int i : ints) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 2, 3, 4}, new int[][]{{1, 0}, {-3, 1}, {-4, 0}, {2, 3}}); // 8,6,2,4
  }
}