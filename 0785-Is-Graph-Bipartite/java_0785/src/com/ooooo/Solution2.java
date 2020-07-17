package com.ooooo;

import java.util.LinkedList;
import java.util.Queue;

/**
 * bfs
 *
 * @author leizhijie
 * @since 2020/7/17 20:53
 */
public class Solution2 {
  
  private int[] color;
  private int uncolor = 0;
  private int red = 1;
  private int green = 2;
  
  public boolean isBipartite(int[][] graph) {
    int n = graph.length;
    color = new int[n];
    Queue<Integer> q = new LinkedList<>();
    for (int i = 0; i < n; i++) {
      if (color[i] == uncolor) {
        q.add(i);
        while (!q.isEmpty()) {
          int k = q.poll();
          if (color[k] == uncolor) {
            color[k] = red;
          }
          int c = color[k] == red ? green : red;
          for (int j : graph[k]) {
            if (color[j] == uncolor) {
              color[j] = c;
              q.add(j);
            } else if (color[j] != c) {
              return false;
            }
          }
        }
      }
    }
    
    return true;
  }
  
  private static void test(int[][] graph) {
    Solution2 solution = new Solution2();
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
