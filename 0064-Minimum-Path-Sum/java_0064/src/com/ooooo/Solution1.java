package com.ooooo;

/**
 * dfs timeout
 */
class Solution1 {
  
  private int min_v = Integer.MAX_VALUE;
  
  private void dfs(int[][] grid, int i, int j, int sum) {
    if (i >= grid.length || j >= grid[i].length) return;
    sum += grid[i][j];
    if (i == grid.length - 1 && j == grid[i].length - 1) {
      min_v = Math.min(min_v, sum);
      return;
    }
    dfs(grid, i + 1, j, sum);
    dfs(grid, i, j + 1, sum);
  }
  
  public int minPathSum(int[][] grid) {
    dfs(grid, 0, 0, 0);
    return min_v;
  }
  
  private static void test(int[][] grid) {
    Solution1 solution = new Solution1();
    int i = solution.minPathSum(grid);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    });
  }
}