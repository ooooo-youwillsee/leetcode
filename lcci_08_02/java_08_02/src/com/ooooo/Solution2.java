package com.ooooo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * @author leizhijie
 * @since 2020/5/21 17:49
 * <p>
 * dp[i][j] = dp[i-1][j] | dp[i][j-1]
 */
public class Solution2 {

  private List<List<Integer>> ans = new ArrayList<>();

  public List<List<Integer>> pathWithObstacles(int[][] grid) {
    if (grid == null || grid.length == 0 || grid[0].length == 0) return ans;
    int row = grid.length, col = grid[0].length;

    int[][] dp = new int[row][col];
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == 1) {
          dp[i][j] = 0;
          continue;
        }
        if (i == 0 && j == 0) {
          dp[i][j] = 1;
        } else if (i == 0) {
          dp[i][j] = dp[i][j - 1];
        } else if (j == 0) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
    }
    if (dp[row - 1][col - 1] == 0) return ans;
    int r = row - 1, c = col - 1;
    while (r > 0 || c > 0) {
      ans.add(Arrays.asList(r, c));
      int up = r > 0 ? dp[r - 1][c] : 0;
      int left = c > 0 ? dp[r][c - 1] : 0;
      if (up >= left) r--;
      else c--;
    }
    ans.add(Arrays.asList(0, 0));
    Collections.reverse(ans);
    return ans;
  }

  private static void test(int[][] grid) {
    Solution2 solution = new Solution2();
    for (List<Integer> step : solution.pathWithObstacles(grid)) {
      System.out.print(String.format("[%d, %d] -> ", step.get(0), step.get(1)));
    }
    System.out.println();
  }

  public static void main(String[] args) {
    test(new int[][]{{0, 0, 0}, {0, 1, 0}, {1, 0, 0}});
  }

}
