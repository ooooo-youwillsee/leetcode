package com.ooooo;

class Solution1 {
  
  public int oddCells(int n, int m, int[][] indices) {
    int[] rows = new int[n], cols = new int[m];
    for (int[] index : indices) {
      rows[index[0]]++;
      cols[index[1]]++;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((rows[i] + cols[j]) % 2 == 1) count++;
      }
    }
    return count;
  }
  
  private static void test(int n, int m, int[][] indices) {
    Solution1 solution = new Solution1();
    int i = solution.oddCells(n, m, indices);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(2, 3, new int[][]{{0, 1}, {1, 1}}); // 6
    test(2, 2, new int[][]{{1, 1}, {0, 0}}); // 0
  }
}