package com.ooooo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

class Solution1 {

  private Set<Integer> set = new HashSet<>();
  private Map<Integer, List<Integer>> map = new HashMap<>();

  private boolean find(int start, int target) {
    set.add(start);
    for (Integer v : map.getOrDefault(start, new ArrayList<>())) {
      if (set.contains(v)) continue;
      if (v == target || find(v, target)) return true;
    }
    return false;
  }

  public boolean findWhetherExistsPath(int n, int[][] graph, int start, int target) {
    if (graph == null || graph.length == 0) return false;
    for (int[] ints : graph) {
      int k = ints[0], v = ints[1];
      List<Integer> values = map.getOrDefault(k, new ArrayList<>());
      values.add(v);
      map.put(k, values);
    }
    return find(start, target);
  }
}