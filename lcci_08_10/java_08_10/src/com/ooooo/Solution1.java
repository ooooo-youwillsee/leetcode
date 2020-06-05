package com.ooooo;

class Solution1 {

  private int[][] dx_dy = new int[][]{
      {0, 1}, {0, -1}, {1, 0}, {-1, 0}
  };

  private void dfs(int[][] image, int i, int j) {
    if (i < 0 || j < 0 || i >= image.length || j >= image[0].length
        || image[i][j] != oldColor)
      return;
    image[i][j] = newColor;
    for (int[] offset : dx_dy) {
      dfs(image, i + offset[0], j + offset[1]);
    }
  }

  private int oldColor = 0, newColor = 0;

  public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
    this.oldColor = image[sr][sc];
    this.newColor = newColor;
    if (this.oldColor == this.newColor) return image;
    dfs(image, sr, sc);
    return image;
  }

  private static void test(int[][] image, int sr, int sc, int newColor) {
    Solution1 solution = new Solution1();
    int[][] ans = solution.floodFill(image, sr, sc, newColor);
    for (int[] ints : ans) {
      for (int i : ints) {
        System.out.print(i + " ");
      }
      System.out.println();
    }
    System.out.println();
  }

  public static void main(String[] args) {
    test(new int[][]{
        {0, 0, 0},
        {0, 1, 1}}, 1, 1, 1);
    test(new int[][]{
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}}, 1, 1, 2);

  }
}