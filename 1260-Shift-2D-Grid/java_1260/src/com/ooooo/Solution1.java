package com.ooooo;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class Solution1 {
  
  public List<List<Integer>> shiftGrid(int[][] grid, int k) {
    int m = grid.length, n = grid[0].length;
    k = k % (m * n);
    int[][] ans = new int[m][n];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int p = i * n + j + k;
        ans[(p / n) % m][p % n] = grid[i][j];
      }
    }
    return Arrays.stream(ans)
        .map(arr -> Arrays.stream(arr).boxed().collect(Collectors.toList()))
        .collect(Collectors.toList());
  }
  
  private static void test(int[][] grid, int k) {
    Solution1 solution = new Solution1();
    List<List<Integer>> shiftGrid = solution.shiftGrid(grid, k);
    shiftGrid.forEach(row -> {
      row.forEach(col -> System.out.print(col + " "));
      System.out.println();
    });
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {3, 8, 1, 9},
        {19, 7, 2, 5},
        {4, 6, 11, 10},
        {12, 0, 21, 13}
    }, 4);
  }
}