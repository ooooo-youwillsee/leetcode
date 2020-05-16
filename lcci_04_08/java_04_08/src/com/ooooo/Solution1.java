package com.ooooo;

import java.util.ArrayList;
import java.util.List;

class Solution1 {

  private boolean dfs(TreeNode node, List<TreeNode> nodes, TreeNode targetNode) {
    if (node == null) return false;
    if (node.val == targetNode.val || dfs(node.left, nodes, targetNode) || dfs(node.right, nodes,
      targetNode)) {
      nodes.add(node);
      return true;
    }
    return false;
  }

  public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    if (p == root || q == root) return root;
    List<TreeNode> pNodes = new ArrayList<>(), qNodes = new ArrayList<>();
    dfs(root, pNodes, p);
    dfs(root, qNodes, q);
    int plen = pNodes.size(), qlen = qNodes.size(), len = Math.min(plen, qlen);
    for (int i = 0; i < len; i++) {
      if (pNodes.get(plen - 1 - i) != qNodes.get(qlen - 1 - i)) return qNodes.get(qlen - i);
    }
    return pNodes.get(plen - len);
  }
}