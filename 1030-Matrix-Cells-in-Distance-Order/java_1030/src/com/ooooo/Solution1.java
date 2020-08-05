package com.ooooo;

import java.util.LinkedList;
import java.util.Queue;

class Solution1 {
  
  private final int[][] dx_dy = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  
  public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
    Queue<int[]> queue = new LinkedList<>();
    boolean[][] visited = new boolean[R][C];
    queue.add(new int[]{r0, c0});
    visited[r0][c0] = true;
    int[][] ans = new int[R * C][2];
    int count = 0;
    while (!queue.isEmpty()) {
      int[] r_c = queue.poll();
      ans[count++] = r_c;
      for (int i = 0; i < 4; i++) {
        int x = r_c[0] + dx_dy[i][0];
        int y = r_c[1] + dx_dy[i][1];
        if (x >= 0 && x < R && y >= 0 && y < C && !visited[x][y]) {
          queue.add(new int[]{x, y});
          visited[x][y] = true;
        }
      }
    }
    return ans;
  }
  
  private static void test(int R, int C, int r0, int c0) {
    Solution1 solution = new Solution1();
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