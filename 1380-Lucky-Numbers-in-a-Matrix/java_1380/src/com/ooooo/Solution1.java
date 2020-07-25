package com.ooooo;

import java.util.ArrayList;
import java.util.List;

class Solution1 {
  
  private static boolean check(int[][] matrix, int i, int j) {
    int val = matrix[i][j];
    for (int k = 0; k < matrix[i].length; k++) {
      if (k != j && matrix[i][k] < val) return false;
    }
    for (int k = 0; k < matrix.length; k++) {
      if (k != i && matrix[k][j] > val) return false;
    }
    return true;
  }
  
  public List<Integer> luckyNumbers(int[][] matrix) {
    List<Integer> ans = new ArrayList<>();
    for (int i = 0; i < matrix.length; i++) {
      for (int j = 0; j < matrix[i].length; j++) {
        if (check(matrix, i, j)) ans.add(matrix[i][j]);
      }
    }
    return ans;
  }
  
  private static void test(int[][] matrix) {
    Solution1 solution = new Solution1();
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