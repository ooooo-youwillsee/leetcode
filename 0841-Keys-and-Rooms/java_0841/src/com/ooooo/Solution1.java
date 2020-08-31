package com.ooooo;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class Solution1 {
  
  private boolean[] visited;
  
  private boolean dfs(List<List<Integer>> rooms, int i) {
    visited[i] = true;
    for (Integer id : rooms.get(i)) {
      if (visited[id]) continue;
      if (dfs(rooms, id)) return true;
    }
    boolean is_all_true = true;
    for (boolean b : visited) {
      is_all_true = is_all_true && b;
    }
    return is_all_true;
  }
  
  public boolean canVisitAllRooms(List<List<Integer>> rooms) {
    if (rooms.isEmpty()) return true;
    this.visited = new boolean[rooms.size()];
    return dfs(rooms, 0);
  }
  
  private static void test(int[][] rooms) {
    List<List<Integer>> collect = Arrays.stream(rooms)
        .map(room -> Arrays.stream(room).boxed().collect(Collectors.toList()))
        .collect(Collectors.toList());
    Solution1 solution = new Solution1();
    boolean b = solution.canVisitAllRooms(collect);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {1}, {2}, {3}, {}
    }); // true
    
    test(new int[][]{
        {1, 3}, {3, 0, 1}, {2}, {0}
    }); // false
  }
}