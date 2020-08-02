package com.ooooo;

/**
 * postOrder
 *
 * @author leizhijie
 * @since 2020/8/2 10:17
 */
public class Solution2 {
  
  private TreeNode prev = null;
  
  public void flatten(TreeNode root) {
    if (root == null) return;
    flatten(root.right);
    flatten(root.left);
    root.right = prev;
    root.left = null;
    prev = root;
  }
  
  private static void test(TreeNode root) {
    Solution2 solution = new Solution2();
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
