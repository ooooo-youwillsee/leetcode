package com.ooooo;

class Solution1 {
  
  public int[][] flipAndInvertImage(int[][] A) {
    for (int i = 0; i < A.length; i++) {
      for (int l = 0, r = A[i].length - 1; l < r; l++, r--) {
        int tmp = A[i][l];
        A[i][l] = A[i][r];
        A[i][r] = tmp;
      }
      for (int j = 0; j < A[i].length; j++) {
        A[i][j] = A[i][j] == 1 ? 0 : 1;
      }
    }
    return A;
  }
  
  public int[][] flipAndInvertImage2(int[][] A) {
    for (int i = 0; i < A.length; i++) {
      for (int l = 0, r = A[i].length - 1; l <= r; l++, r--) {
        if (l == r) {
          A[i][l] = A[i][l] == 1 ? 0 : 1;
          break;
        }
        int tmp = A[i][l];
        A[i][l] = A[i][r] == 1 ? 0 : 1;
        A[i][r] = tmp == 1 ? 0 : 1;
        
      }
    }
    return A;
  }
  
  private static void test(int[][] A) {
    Solution1 solution = new Solution1();
    int[][] ints = solution.flipAndInvertImage(A);
    for (int[] anInt : ints) {
      for (int i : anInt) {
        System.out.print(i + " ");
      }
      System.out.println();
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {1, 1, 0},
        {1, 0, 1},
        {0, 0, 0}
    });
  }
}