package com.ooooo;

import java.util.HashMap;
import java.util.Map;

/**
 * dfs
 */
class Solution1 {
  
  private Map<TreeNode, Integer> memo = new HashMap<>();
  
  private int getH(TreeNode root) {
    if (root == null) return 0;
    return memo.computeIfAbsent(root, k -> Math.max(getH(root.left), getH(root.right)) + 1);
  }
  
  public boolean isBalanced(TreeNode root) {
    if (root == null) return true;
    return isBalanced(root.left) && isBalanced(root.right) && Math.abs(getH(root.left) - getH(root.right)) <= 1;
  }
  
  private static void test(TreeNode root) {
    Solution1 solution = new Solution1();
    boolean balanced = solution.isBalanced(root);
    System.out.println(balanced);
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