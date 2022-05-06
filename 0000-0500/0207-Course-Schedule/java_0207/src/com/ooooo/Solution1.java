package com.ooooo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

/**
 * 拓扑排序 bfs
 */
class Solution1 {
  
  public boolean canFinish(int numCourses, int[][] prerequisites) {
    int[] courses = new int[numCourses];
    Map<Integer, List<Integer>> g = new HashMap<>();
    for (int[] pre : prerequisites) {
      courses[pre[0]]++;
      List<Integer> others = g.computeIfAbsent(pre[1], k -> new ArrayList<>());
      others.add(pre[0]);
    }
    
    Queue<Integer> q = new LinkedList<>();
    for (int i = 0; i < courses.length; i++) {
      if (courses[i] == 0) q.add(i);
    }
    
    int count = 0;
    while (!q.isEmpty()) {
      count++;
      Integer i = q.poll();
      List<Integer> others = g.getOrDefault(i, new ArrayList<>());
      for (Integer j : others) {
        courses[j]--;
        if (courses[j] == 0) q.add(j);
      }
    }
    return count == numCourses;
  }
  
  private static void test(int num, int[][] prerequisites) {
    Solution1 solution = new Solution1();
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