package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/7/21 13:42
 */
public class Solution2 {
  
  public int countNegatives(int[][] grid) {
    int count = 0, m = grid.length, n = grid[0].length;
    int i = 0, j = n - 1;
    while (i >= 0 && i < m && j >= 0 && j < n) {
      if (grid[i][j] < 0) {
        count += (m - i);
        j--;
      } else {
        i++;
      }
    }
    return count;
  }
  
  private static void test(int[][] grid) {
    Solution2 solution = new Solution2();
    int i = solution.countNegatives(grid);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}
    }); // 8
    
    test(new int[][]{
        {1, -1}, {-1, -1}
    }); // 3
  }
}
