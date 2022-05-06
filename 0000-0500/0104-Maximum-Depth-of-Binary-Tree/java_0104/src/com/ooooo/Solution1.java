package com.ooooo;

/**
 * 分治法
 */
class Solution1 {
  
  public int maxDepth(TreeNode root) {
    if (root == null) return 0;
    return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
  }
  
  
  public static void main(String[] args) {
    TreeNode root = new TreeNode(3);
    root.left = new TreeNode(9);
    root.right = new TreeNode(20);
    root.right.left = new TreeNode(15);
    root.right.right = new TreeNode(7);
    Solution1 solution = new Solution1();
    int i = solution.maxDepth(root);
    System.out.println(i);
  }
}