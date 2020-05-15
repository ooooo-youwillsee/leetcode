package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/5/15 18:02
 */
public class Solution2 {

  public void dfs(TreeNode node) {
    if (node == null) return;
    dfs(node.left);
    if (prev == null) {
      prev = node;
    } else {
      prev.right = node;
      prev = prev.right;
    }
    dfs(node.right);
  }

  private TreeNode prev = null;

  public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
    if (p == null || root == null) return null;
    dfs(root);
    return p.right;
  }

}
