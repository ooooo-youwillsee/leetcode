package com.ooooo;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

/**
 * bfs
 *
 * @author leizhijie
 * @since 2020/8/12 19:46
 */
public class Solution2 {
  
  private final Map<Integer, Node> map = new HashMap<>();
  
  public Node cloneGraph(Node node) {
    if (node == null) return null;
    Queue<Node> queue = new LinkedList<>();
    map.put(node.val, new Node(node.val));
    queue.add(node);
    while (!queue.isEmpty()) {
      Node poll = queue.poll();
      for (Node neighbor : poll.neighbors) {
        if (!map.containsKey(neighbor.val)) {
          map.put(neighbor.val, new Node(neighbor.val));
          queue.add(neighbor);
        }
        map.get(poll.val).neighbors.add(map.get(neighbor.val));
      }
    }
    
    return map.get(node.val);
  }
  
  private static void test(Node node) {
    Solution2 solution = new Solution2();
    Node ans = solution.cloneGraph(node);
    System.out.println();
  }
}
