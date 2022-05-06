package com.ooooo;

class Solution1 {
  
  public int countNegatives(int[][] grid) {
    int count = 0;
    for (int[] ints : grid) {
      for (int num : ints) {
        if (num < 0) count++;
      }
    }
    return count;
  }
  
  private static void test(int[][] grid) {
    Solution1 solution = new Solution1();
    int i = solution.countNegatives(grid);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}
    }); // 8
  }
}