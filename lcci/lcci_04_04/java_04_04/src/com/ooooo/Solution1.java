package com.ooooo;

class Solution1 {

  private int getH(TreeNode node) {
    if (node == null) return 0;
    return Math.max(getH(node.left), getH(node.right)) + 1;
  }

  public boolean isBalanced(TreeNode root) {
    if (root == null) return true;
    return isBalanced(root.left) && isBalanced(root.right)
        && Math.abs(getH(root.left) - getH(root.right)) <= 1;
  }
}