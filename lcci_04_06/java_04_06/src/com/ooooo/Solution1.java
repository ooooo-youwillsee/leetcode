package com.ooooo;

import java.util.ArrayList;
import java.util.List;

class Solution1 {

  public void dfs(TreeNode node) {
    if (node == null) return;
    dfs(node.left);
    nodes.add(node);
    dfs(node.right);
  }

  private TreeNode next = null;
  private List<TreeNode> nodes = new ArrayList<>();

  public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
    dfs(root);
    for (int i = 0, len = nodes.size() - 1; i < len; i++) {
      if (nodes.get(i) == p) return nodes.get(i + 1);
    }
    return null;
  }
}