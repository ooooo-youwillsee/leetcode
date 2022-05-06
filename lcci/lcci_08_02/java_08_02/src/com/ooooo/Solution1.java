package com.ooooo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * dfs timeout
 */
class Solution1 {

  private boolean dfs(int i, int j, int[][] grid) {
    if (i >= grid.length || j >= grid[0].length || grid[i][j] == 1) return false;
    ans.add(Arrays.asList(i, j));
    if (i == grid.length - 1 && j == grid[0].length - 1) return true;
    boolean can = dfs(i + 1, j, grid) || dfs(i, j + 1, grid);
    if (!can) {
      ans.remove(ans.size() - 1);
      grid[i][j] = 1;  // 向下向右走都不行，说明当前节点也是故障节点
    }
    return can;
  }

  private List<List<Integer>> ans = new ArrayList<>();

  public List<List<Integer>> pathWithObstacles(int[][] obstacleGrid) {
    return dfs(0, 0, obstacleGrid) ? ans : new ArrayList<>();
  }

  private static void test(int[][] grid) {
    Solution1 solution = new Solution1();
    for (List<Integer> step : solution.pathWithObstacles(grid)) {
      System.out.print(String.format("[%d, %d] -> ", step.get(0), step.get(1)));
    }
    System.out.println();
  }

  public static void main(String[] args) {
    test(new int[][]{{0, 0, 0}, {0, 1, 0}, {1, 0, 0}});
  }
}