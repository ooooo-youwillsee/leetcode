package com.ooooo;

class Solution1 {
  
  public int minTimeToVisitAllPoints(int[][] points) {
    int ans = 0;
    for (int i = 1; i < points.length; i++) {
      int x = Math.abs(points[i][0] - points[i - 1][0]);
      int y = Math.abs(points[i][1] - points[i - 1][1]);
      ans += Math.max(x, y);
    }
    return ans;
  }
  
  private static void test(int[][] points) {
    Solution1 solution = new Solution1();
    int i = solution.minTimeToVisitAllPoints(points);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {1, 1}, {3, 4}, {-1, 0}
    }); // 7
  }
}