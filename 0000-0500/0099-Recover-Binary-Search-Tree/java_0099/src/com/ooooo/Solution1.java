package com.ooooo;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

class Solution1 {
  
  private void dfs(TreeNode root, List<TreeNode> nodes) {
    if (root == null) return;
    dfs(root.left, nodes);
    nodes.add(root);
    dfs(root.right, nodes);
  }
  
  public void recoverTree(TreeNode root) {
    List<TreeNode> nodes = new ArrayList<>();
    dfs(root, nodes);
    List<TreeNode> nodeList = new ArrayList<>(nodes);
    nodeList.sort(Comparator.comparingInt(o -> o.val));
    TreeNode node1 = null, node2 = null;
    for (int i = 0; i < nodes.size(); i++) {
      if (nodes.get(i).val != nodeList.get(i).val) {
        if (node1 == null) {
          node1 = nodes.get(i);
          continue;
        }
        if (node2 == null) {
          node2 = nodes.get(i);
          break;
        }
      }
    }
    int tmp = node1.val;
    node1.val = node2.val;
    node2.val = tmp;
  }
  
  
  private static void test(TreeNode root) {
    Solution1 solution = new Solution1();
    solution.recoverTree(root);
    System.out.println();
  }
  
  public static void main(String[] args) {
    TreeNode root3 = new TreeNode(2);
    root3.left = new TreeNode(3);
    root3.right = new TreeNode(1);
    test(root3);
    
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(3);
    root.left.right = new TreeNode(2);
    test(root);
    
    TreeNode root2 = new TreeNode(3);
    root2.left = new TreeNode(1);
    root2.right = new TreeNode(4);
    root2.right.left = new TreeNode(2);
    test(root2);
  }
}