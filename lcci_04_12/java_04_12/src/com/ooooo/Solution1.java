package com.ooooo;

class Solution1 {

  /**
   * @param node
   * @param sum  剩余的值
   * @param flag 前面的节点是否开始减值
   */
  private void dfs(TreeNode node, int sum, boolean flag) {
    if (node == null) return;
    if (!flag) {
      dfs(node.left, sum, flag);
      dfs(node.right, sum, flag);
    }
    sum -= node.val;
    if (sum == 0) count++;
    dfs(node.left, sum, true);
    dfs(node.right, sum, true);
  }

  private int count = 0;

  public int pathSum(TreeNode root, int sum) {
    dfs(root, sum, false);
    return count;
  }
}