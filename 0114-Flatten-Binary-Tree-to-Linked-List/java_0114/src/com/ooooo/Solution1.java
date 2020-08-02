package com.ooooo;

class Solution1 {
  
  private TreeNode dfs(TreeNode node) {
    if (node == null) return null;
    TreeNode left = dfs(node.left);
    TreeNode right = dfs(node.right);
    node.right = left;
    node.left = null;
    TreeNode temp = node;
    while (temp.right != null) {
      temp = temp.right;
    }
    temp.right = right;
    return node;
  }
  
  public void flatten(TreeNode root) {
    dfs(root);
  }
  
  private static void test(TreeNode root) {
    Solution1 solution = new Solution1();
    solution.flatten(root);
    while (root != null) {
      System.out.print(root.val + " -> ");
      root = root.right;
    }
    System.out.println();
  }
  
  
  public static void main(String[] args) {
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(5);
    root.left.left = new TreeNode(3);
    root.left.right = new TreeNode(4);
    root.right.right = new TreeNode(6);
    test(root);
  }
}