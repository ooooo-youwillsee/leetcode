package com.ooooo;

class Solution1 {
  
  private final int[][] dx_dy = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  private int origin_color;
  
  private boolean check(int[][] image, int i, int j) {
    return i < image.length && i >= 0 && j < image[0].length && j >= 0 && image[i][j] == origin_color;
  }
  
  private void dfs(int[][] image, int sr, int sc, int newColor) {
    if (!check(image, sr, sc)) return;
    image[sr][sc] = newColor;
    for (int i = 0; i < 4; i++) {
      int nr = sr + dx_dy[i][0];
      int nc = sc + dx_dy[i][1];
      dfs(image, nr, nc, newColor);
    }
  }
  
  public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
    this.origin_color = image[sr][sc];
    if (newColor == origin_color) return image;
    dfs(image, sr, sc, newColor);
    return image;
  }
  
  
  private static void test(int[][] image, int sr, int sc, int newColor) {
    Solution1 solution = new Solution1();
    int[][] floodFill = solution.floodFill(image, sr, sc, newColor);
    for (int[] ints : floodFill) {
      for (int i : ints) {
        System.out.print(i + " ");
      }
      System.out.println();
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[][]{
            {1, 1, 1},
            {1, 1, 0},
            {1, 0, 1}},
        1, 1, 2);
    
    test(new int[][]{
        {0, 0, 0},
        {0, 1, 1}
    }, 1, 1, 1);
  }
}