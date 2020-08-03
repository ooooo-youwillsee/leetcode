package com.ooooo;

import java.util.Arrays;

class Solution1 {
  
  public int projectionArea(int[][] grid) {
    int count = 0;
    int[] rows = new int[grid.length], cols = new int[grid.length];
    for (int i = 0; i < grid.length; i++) {
      for (int j = 0; j < grid[i].length; j++) {
        if (grid[i][j] > 0) count++;
        rows[i] = Math.max(rows[i], grid[i][j]);
        cols[j] = Math.max(cols[j], grid[i][j]);
      }
    }
    return count + Arrays.stream(rows).sum() + Arrays.stream(cols).sum();
  }
  
  private static void test(int[][] grid) {
    Solution1 solution = new Solution1();
    int i = solution.projectionArea(grid);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {2},
    }); // 5
    
    test(new int[][]{
        {1, 2},
        {3, 4}
    }); // 17
    
    test(new int[][]{
        {1, 0},
        {0, 2}
    }); // 8
  }
}