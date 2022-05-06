package com.ooooo;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * dfs timeout
 * @author leizhijie
 * @since 2020/7/14 19:42
 */
public class Solution2 {
  
  
  private int min_v = Integer.MAX_VALUE;
  
  private void dfs(List<List<Integer>> triangle, int i, int j, int sum) {
    if (i >= triangle.size() || j >= triangle.get(i).size()) return;
    sum += triangle.get(i).get(j);
    if (i == triangle.size() - 1) {
      min_v = Math.min(min_v, sum);
      return;
    }
    dfs(triangle, i + 1, j, sum);
    dfs(triangle, i + 1, j + 1, sum);
  }
  
  public int minimumTotal(List<List<Integer>> triangle) {
    dfs(triangle, 0, 0, 0);
    return min_v;
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
    Solution2 solution = new Solution2();
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
