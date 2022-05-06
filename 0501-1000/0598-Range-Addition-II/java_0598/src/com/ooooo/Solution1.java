package com.ooooo;

class Solution1 {
  
  public int maxCount(int m, int n, int[][] ops) {
    int x = m, y = n;
    for (int[] op : ops) {
      x = Math.min(x, op[0]);
      y = Math.min(y, op[1]);
    }
    return x * y;
  }
  
  
  private static void test(int m, int n, int[][] ops) {
    Solution1 solution = new Solution1();
    int i = solution.maxCount(m, n, ops);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(3, 3, new int[][]{
        {2, 2}, {3, 3}
    });
  }
  
}