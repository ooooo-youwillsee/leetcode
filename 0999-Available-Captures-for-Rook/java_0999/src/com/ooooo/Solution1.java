package com.ooooo;

class Solution1 {
  
  int[][] dx_dy = new int[][]{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
  
  public int numRookCaptures(char[][] board) {
    int R_x = 0, R_y = 0;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (board[i][j] == 'R') {
          R_x = i;
          R_y = j;
        }
      }
    }
    
    int count = 0;
    for (int i = 0; i < 4; i++) {
      int step = 1;
      while (true) {
        int new_x = R_x + dx_dy[i][0] * step;
        int new_y = R_y + dx_dy[i][1] * step;
        if (new_x < 0 || new_x >= 8 || new_y < 0 || new_y >= 8
            || board[new_x][new_y] == 'B') break;
        if (board[new_x][new_y] == 'p') {
          count++;
          break;
        }
        step++;
      }
    }
    return count;
  }
  
  private static void test(char[][] board) {
    Solution1 solution = new Solution1();
    int i = solution.numRookCaptures(board);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new char[][]{
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'p', '.', '.', '.', '.'},
        {'.', '.', '.', 'R', '.', '.', '.', 'p'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'p', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'}
    });
  }
}