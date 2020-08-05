package com.ooooo;

import java.util.Arrays;

class Solution1 {
  
  private static class Row {
    
    private int count;
    private int i;
    
    public Row(int count, int i) {
      this.count = count;
      this.i = i;
    }
  }
  
  public int[] kWeakestRows(int[][] mat, int k) {
    Row[] rows = new Row[mat.length];
    for (int i = 0; i < mat.length; i++) {
      int count = (int) Arrays.stream(mat[i]).filter(p -> p == 1).count();
      rows[i] = new Row(count, i);
    }
    Arrays.sort(rows, (o1, o2) -> o1.count == o2.count ? o1.i - o2.i : o1.count - o2.count);
    int[] ans = new int[k];
    for (int i = 0; i < k; i++) {
      ans[i] = rows[i].i;
    }
    return ans;
  }
  
  private static void test(int[][] mat, int k) {
    Solution1 solution = new Solution1();
    int[] ints = solution.kWeakestRows(mat, k);
    for (int i : ints) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
    }, 2); // 0,2
  }
}