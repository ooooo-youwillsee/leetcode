package com.ooooo;

/**
 * dfs
 */
class Solution1 {
  
  private int[] color;
  private int uncolor = 0;
  private int red = 1;
  private int green = 2;
  private boolean valid = true;
  
  private void dfs(int[][] graph, int i, int c) {
    color[i] = c;
    c = c == red ? green : red;
    for (int j : graph[i]) {
      if (color[j] == uncolor) {
        dfs(graph, j, c);
      } else if (color[j] != c) {
        valid = false;
        break;
      }
    }
  }
  
  public boolean isBipartite(int[][] graph) {
    int n = graph.length;
    color = new int[n];
    for (int i = 0; i < n && valid; i++) {
      if (color[i] == uncolor) {
        dfs(graph, i, red);
      }
    }
    return valid;
  }
  
  private static void test(int[][] graph) {
    Solution1 solution = new Solution1();
    boolean b = solution.isBipartite(graph);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {1}, {0, 3}, {3}, {1, 2}
    }); // true
    
    test(new int[][]{
        {1, 3}, {0, 2}, {1, 3}, {0, 2}
    }); // true
    
    test(new int[][]{
        {1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}
    }); // false
    
    
  }
}