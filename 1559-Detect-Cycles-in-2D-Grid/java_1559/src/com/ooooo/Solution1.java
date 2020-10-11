package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/8/22 23:17
 */
public class Solution1 {
  
  private final int[][] dx_dy = new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  private boolean[][] visited;
  
  private boolean inArea(char[][] grid, int i, int j) {
    return i >= 0 && i < grid.length && j >= 0 && j < grid[0].length;
  }
  
  private boolean dfs(char[][] grid, int x, int y, int srci, int srcj) {
    visited[x][y] = true;
    for (int k = 0; k < 4; k++) {
      int nx = x + dx_dy[k][0];
      int ny = y + dx_dy[k][1];
      // 越界 或者 不是相同的颜色， 跳过
      if (!inArea(grid, nx, ny) || grid[nx][ny] != grid[x][y]) continue;
      // 如果和父节点一样，跳过
      if (nx == srci && ny == srcj) continue;
      // 不是父节点，而这个点又被访问过，说明是环
      if (visited[nx][ny]) return true;
      if (dfs(grid, nx, ny, x, y)) {
        return true;
      }
    }
    return false;
  }
  
  public boolean containsCycle(char[][] grid) {
    if (grid.length == 0) return false;
    visited = new boolean[grid.length][grid[0].length];
    for (int i = 0; i < grid.length; i++) {
      for (int j = 0; j < grid[i].length; j++) {
        // 已经访问过的点，没有return,说明这个点就不可能成环，所以要跳过
        if (!visited[i][j] && dfs(grid, i, j, i, j)) {
          return true;
        }
      }
    }
    return false;
  }
  
  private static void test(char[][] grid) {
    Solution1 solution = new Solution1();
    boolean b = solution.containsCycle(grid);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    
    test(new char[][]{
        {'f', 'a', 'a', 'c', 'b'},
        {'e', 'a', 'a', 'e', 'c'},
        {'c', 'f', 'b', 'b', 'b'},
        {'c', 'e', 'a', 'b', 'e'},
        {'f', 'e', 'f', 'b', 'f'}
    }); // true
    
    test(new char[][]{
        {'a', 'a', 'a', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'a', 'a', 'a'}
    }); // true
    
    test(new char[][]{
        {'a', 'b', 'b'},
        {'b', 'z', 'b'},
        {'b', 'b', 'a'}
    }); // false
    
    test(new char[][]{
        {'c', 'a', 'd'},
        {'a', 'a', 'a'},
        {'a', 'a', 'd'},
        {'a', 'c', 'd'},
        {'a', 'b', 'c'}
    }); // true
  }
}
