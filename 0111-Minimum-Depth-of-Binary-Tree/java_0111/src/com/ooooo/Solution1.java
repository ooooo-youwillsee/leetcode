package com.ooooo;

/**
 * dfs
 */
class Solution1 {
  
  private int depth = Integer.MAX_VALUE;
  
  private void dfs(TreeNode root, int level) {
    if (root == null) return;
    if (root.left == null && root.right == null) {
      depth = Math.min(depth, level);
      return;
    }
    dfs(root.left, level + 1);
    dfs(root.right, level + 1);
  }
  
  public int minDepth(TreeNode root) {
    if (root == null) return 0;
    dfs(root, 1);
    return depth;
  }
  
  private static void test(TreeNode root) {
    Solution1 solution = new Solution1();
    int minDepth = solution.minDepth(root);
    System.out.println(minDepth);
  }
  
  public static void main(String[] args) {
    TreeNode root = new TreeNode(3);
    root.left = new TreeNode(9);
    root.right = new TreeNode(20);
    root.right.left = new TreeNode(15);
    root.right.right = new TreeNode(7);
    test(root);
  }
}