package com.ooooo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author leizhijie
 * @since 2020/7/25 21:36
 */
public class Solution2 {
  
  public List<Integer> luckyNumbers(int[][] matrix) {
    List<Integer> ans = new ArrayList<>();
    // 预处理
    int[] rowMin = new int[matrix.length];
    Arrays.fill(rowMin, Integer.MAX_VALUE);
    int[] colMax = new int[matrix[0].length];
    for (int i = 0; i < matrix.length; i++) {
      for (int j = 0; j < matrix[i].length; j++) {
        rowMin[i] = Math.min(rowMin[i], matrix[i][j]);
        colMax[j] = Math.max(colMax[j], matrix[i][j]);
      }
    }
    for (int i = 0; i < matrix.length; i++) {
      for (int j = 0; j < matrix[i].length; j++) {
        if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) ans.add(matrix[i][j]);
      }
    }
    return ans;
  }
  
  private static void test(int[][] matrix) {
    Solution2 solution = new Solution2();
    List<Integer> list = solution.luckyNumbers(matrix);
    for (Integer i : list) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {3, 7, 8},
        {9, 11, 13},
        {15, 16, 17}
    }); // 15
  }
}
