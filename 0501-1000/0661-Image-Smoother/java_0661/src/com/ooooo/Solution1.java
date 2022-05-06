package com.ooooo;

class Solution1 {
  
  int m, n;
  int[][] M;
  
  private int calc(int[][] M, int i, int j) {
    int sum = 0, count = 0;
    for (int k = i - 1; k <= i + 1; k++) {
      if (k >= 0 && k < m) {
        sum += M[k][j];
        count++;
        if (j > 0) {
          sum += M[k][j - 1];
          count++;
        }
        if (j + 1 < n) {
          sum += M[k][j + 1];
          count++;
        }
      }
    }
    return (int) Math.floor(sum * 1.0 / count);
  }
  
  public int[][] imageSmoother(int[][] M) {
    if (M.length == 0) return new int[0][0];
    this.m = M.length;
    this.n = M[0].length;
    this.M = M;
    int[][] images = new int[m][n];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < M[i].length; j++) {
        images[i][j] = calc(M, i, j);
      }
    }
    return images;
  }
  
  
  private static void test(int[][] M) {
    Solution1 solution = new Solution1();
    int[][] imageSmoother = solution.imageSmoother(M);
    for (int[] ints : imageSmoother) {
      for (int anInt : ints) {
        System.out.print(anInt + " ");
      }
      System.out.println();
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {2, 3, 4},
        {5, 6, 7},
        {8, 9, 10},
        {11, 12, 13},
        {14, 15, 16}
    });
    
    test(new int[][]{
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    });
  }
}