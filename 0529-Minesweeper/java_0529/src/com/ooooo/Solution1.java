package com.ooooo;

class Solution1 {
  
  private char[][] board;
  private int m, n;
  // 向周围发散
  private final int[][] dx_dy = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  
  private boolean inArea(int i, int j) {
    return i >= 0 && i < m && j >= 0 && j < n;
  }
  
  private int countM(int i, int j) {
    int count = 0;
    for (int k = i - 1; k <= i + 1; k++) {
      for (int l = j - 1; l <= j + 1; l++) {
        if (inArea(k, l) && board[k][l] == 'M') count++;
      }
    }
    return count;
  }
  
  private void dfs(int i, int j) {
    int M_count = countM(i, j);
    if (M_count == 0) {
      board[i][j] = 'B';
    } else {
      board[i][j] = (char) ('0' + M_count);
      return;
    }
    
    for (int k = 0; k < 8; k++) {
      int ni = i + dx_dy[k][0];
      int nj = j + dx_dy[k][1];
      if (!inArea(ni, nj) || board[ni][nj] != 'E') continue;
      dfs(ni, nj);
    }
  }
  
  public char[][] updateBoard(char[][] board, int[] click) {
    this.board = board;
    this.m = board.length;
    this.n = board[0].length;
    int i = click[0], j = click[1];
    if (board[i][j] == 'M') {
      board[i][j] = 'X';
    } else {
      dfs(i, j);
    }
    return board;
  }
  
  
  private static void test(char[][] board, int[] click) {
    Solution1 solution = new Solution1();
    char[][] updateBoard = solution.updateBoard(board, click);
    for (char[] chars : updateBoard) {
      for (char aChar : chars) {
        System.out.print(aChar + " ");
      }
      System.out.println();
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new char[][]{
        {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'M'},
        {'E', 'E', 'M', 'E', 'E', 'E', 'E', 'E'},
        {'M', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'M', 'M', 'E', 'E', 'E', 'E'}
    }, new int[]{0, 0});
    /*
     * [["B","B","B","B","B","B","1","E"],
     * ["B","1","1","1","B","B","1","M"],
     * ["1","2","M","1","B","B","1","1"],
     * ["M","2","1","1","B","B","B","B"],
     * ["1","1","B","B","B","B","B","B"],
     * ["B","B","B","B","B","B","B","B"],
     * ["B","1","2","2","1","B","B","B"],
     * ["B","1","M","M","1","B","B","B"]]
     *
     * */
    
    test(new char[][]{
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'M', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'}
    }, new int[]{3, 0});
    
    test(new char[][]{
        {'B', '1', 'E', '1', 'B'},
        {'B', '1', 'M', '1', 'B'},
        {'B', '1', '1', '1', 'B'},
        {'B', 'B', 'B', 'B', 'B'}
    }, new int[]{1, 2});
  }
}