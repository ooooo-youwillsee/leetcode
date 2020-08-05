package com.ooooo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 桶排序
 * @author leizhijie
 * @since 2020/8/5 13:48
 */
public class Solution3 {
  
  
  public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
    Map<Integer, List<int[]>> map = new HashMap<>(R + C);
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        int[] r_c = new int[]{i, j};
        int d = Math.abs(r_c[0] - r0) + Math.abs(r_c[1] - c0);
        map.computeIfAbsent(d, k -> new ArrayList<>()).add(r_c);
      }
    }
    
    int[][] ans = new int[R * C][2];
    int k = 0;
    for (int i = 0; i <= R + C; i++) {
      List<int[]> groups = map.getOrDefault(i, new ArrayList<>());
      for (int[] group : groups) {
        ans[k++] = group;
      }
    }
    return ans;
  }
  
  private static void test(int R, int C, int r0, int c0) {
    Solution3 solution = new Solution3();
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
