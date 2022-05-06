package com.ooooo;

import java.util.ArrayList;
import java.util.List;


/**
 * dp
 */
class Solution1 {
  
  public int minimumTotal(List<List<Integer>> triangle) {
    int m = triangle.size(), n = triangle.get(m - 1).size();
    int[][] dp = new int[m + 1][n + 1];
    for (int i = m - 1; i >= 0; i--) {
      for (int j = i; j >= 0; j--) {
        dp[i][j] = Math.min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle.get(i).get(j);
      }
    }
    return dp[0][0];
  }
  
  private static void test(int[][] nums) {
    List<List<Integer>> triangle = new ArrayList<>();
    for (int[] num : nums) {
      ArrayList<Integer> list = new ArrayList<>();
      for (int i : num) {
        list.add(i);
      }
      triangle.add(list);
    }
    Solution1 solution = new Solution1();
    int i = solution.minimumTotal(triangle);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    });
  }
}