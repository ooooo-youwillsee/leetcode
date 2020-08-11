package com.ooooo;

/**
 * 从边界开始出发，如果是'O',标记为true.
 */
class Solution1 {
  
  private int m, n;
  private final int[][] dx_dy = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  private boolean[][] visited;
  
  private boolean inArea(int i, int j) {
    return i >= 0 && i < m && j >= 0 && j < n;
  }
  
  private void dfs(char[][] board, int i, int j) {
    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
      int ni = i + dx_dy[k][0];
      int nj = j + dx_dy[k][1];
      if (!inArea(ni, nj) || board[ni][nj] == 'X' || visited[ni][nj]) continue;
      if (board[ni][nj] == 'O') dfs(board, ni, nj);
    }
  }
  
  public void solve(char[][] board) {
    if (board.length == 0) return;
    this.m = board.length;
    this.n = board[0].length;
    this.visited = new boolean[m][n];
    
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // 边界出发
        if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O') {
          dfs(board, i, j);
        }
      }
    }
    
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // 没有访问过的，就是封闭的
        if (board[i][j] == 'O' && !visited[i][j]) {
          board[i][j] = 'X';
        }
      }
    }
    
  }
  
  private static void test(char[][] board) {
    Solution1 solution = new Solution1();
    solution.solve(board);
    for (char[] chars : board) {
      for (char aChar : chars) {
        System.out.print(aChar + " ");
      }
      System.out.println();
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new char[][]{
        {'O', 'O', 'O'},
        {'O', 'O', 'O'},
        {'O', 'O', 'O'}
    });
    
    test(new char[][]{
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    });
    
    
  }
}