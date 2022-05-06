package com.ooooo;

import java.util.HashSet;
import java.util.Set;

/**
 * @author leizhijie
 * @since 2020/5/2 08:52
 */
public class Solution1 {

  public void setZeroes(int[][] matrix) {
    if (matrix == null) return;
    Set<Integer> cols = new HashSet<>(), rows = new HashSet<>();
    for (int i = 0; i < matrix.length; i++) {
      for (int j = 0; j < matrix[0].length; j++) {
        if (matrix[i][j] == 0) {
          rows.add(i);
          cols.add(j);
        }
      }
    }

    for (int i = 0; i < matrix.length; i++) {
      for (int j = 0; j < matrix[0].length; j++) {
        if (cols.contains(j) || rows.contains(i)) matrix[i][j] = 0;
      }
    }
  }

  private static void test(int[][] matrix) {
    Solution1 solution = new Solution1();
    solution.setZeroes(matrix);
    for (int[] ints : matrix) {
      for (int anInt : ints) {
        System.out.print(anInt + " ");
      }
      System.out.println();
    }
    System.out.println();
  }

  public static void main(String[] args) {
    test(new int[][]{
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    });
  }
}
