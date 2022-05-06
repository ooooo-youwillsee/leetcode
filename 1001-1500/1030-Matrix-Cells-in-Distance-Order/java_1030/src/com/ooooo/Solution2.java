package com.ooooo;

import java.util.Arrays;

/**
 * sort
 *
 * @author leizhijie
 * @since 2020/8/5 13:42
 */
public class Solution2 {
  
  
  public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
    int[][] ans = new int[R * C][2];
    int k = 0;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        ans[k++] = new int[]{i, j};
      }
    }
    Arrays.sort(ans, (o1, o2) -> {
      int d1 = Math.abs(o1[0] - r0) + Math.abs(o1[1] - c0);
      int d2 = Math.abs(o2[0] - r0) + Math.abs(o2[1] - c0);
      return d1 - d2;
    });
    return ans;
  }
  
  private static void test(int R, int C, int r0, int c0) {
    Solution2 solution = new Solution2();
    int[][] order = solution.allCellsDistOrder(R, C, r0, c0);
    for (int[] ints : order) {
      System.out.print(String.format("[%d, %d] ", ints[0], ints[1]));
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(2, 3, 1, 2);
  }
}
