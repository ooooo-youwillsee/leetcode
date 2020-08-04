package com.ooooo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * 拓扑排序 dfs
 * @author leizhijie
 * @since 2020/8/4 12:14
 */
public class Solution2 {
  
  private Set<Integer> finished = new HashSet<>();
  
  private boolean dfs(int v, Map<Integer, List<Integer>> g, boolean[] visited) {
    visited[v] = true;
    List<Integer> others = g.getOrDefault(v, new ArrayList<>());
    for (Integer o : others) {
      if (!visited[o] && !dfs(o, g, visited)) return false;
      // o 已经访问过了，但是现在需要 o
      else if (!finished.contains(o)) return false;
    }
    // others 都完成了，再完成这个
    finished.add(v);
    return true;
  }
  
  public boolean canFinish(int numCourses, int[][] prerequisites) {
    boolean[] visited = new boolean[numCourses];
    Map<Integer, List<Integer>> g = new HashMap<>();
    for (int[] pre : prerequisites) {
      List<Integer> others = g.computeIfAbsent(pre[0], k -> new ArrayList<>());
      others.add(pre[1]);
    }
    for (int i = 0; i < numCourses; i++) {
      if (!visited[i]) {
        if (!dfs(i, g, visited)) return false;
      }
    }
    return true;
  }
  
  
  private static void test(int num, int[][] prerequisites) {
    Solution2 solution = new Solution2();
    boolean b = solution.canFinish(num, prerequisites);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test(2, new int[][]{
        {1, 0}
    });
    
    test(2, new int[][]{
        {1, 0}, {0, 1}
    });
  }
}
