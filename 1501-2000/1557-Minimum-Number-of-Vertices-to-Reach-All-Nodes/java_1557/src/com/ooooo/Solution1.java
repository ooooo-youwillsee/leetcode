package com.ooooo;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * @author leizhijie
 * @since 2020/8/22 22:57
 */
public class Solution1 {
  
  public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
    Set<Integer> visited = new HashSet<>(n);
    for (List<Integer> edge : edges) {
      visited.add(edge.get(1));
    }
    
    List<Integer> ans = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      if (!visited.contains(i)) ans.add(i);
    }
    return ans;
  }
}
