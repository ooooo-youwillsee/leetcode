package com.ooooo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * dfs
 */
class Solution1 {
  
  private final Map<Integer, Node> map = new HashMap<>();
  
  public Node cloneGraph(Node node) {
    if (node == null) return null;
    if (map.containsKey(node.val)) return map.get(node.val);
    Node new_node = map.computeIfAbsent(node.val, (k) -> new Node(node.val));
    for (Node neighbor : node.neighbors) {
      new_node.neighbors.add(cloneGraph(neighbor));
    }
    return new_node;
  }
  
  private static void test(Node node) {
    Solution1 solution = new Solution1();
    Node ans = solution.cloneGraph(node);
    System.out.println();
  }
  
  public static void main(String[] args) {
    Node node1 = new Node(1);
    Node node2 = new Node(2);
    Node node3 = new Node(3);
    Node node4 = new Node(4);
    node1.neighbors.addAll(new ArrayList<>(Arrays.asList(node2, node4)));
    node2.neighbors.addAll(new ArrayList<>(Arrays.asList(node1, node3)));
    node3.neighbors.addAll(new ArrayList<>(Arrays.asList(node2, node4)));
    node4.neighbors.addAll(new ArrayList<>(Arrays.asList(node1, node3)));
    test(node1);
  }
}