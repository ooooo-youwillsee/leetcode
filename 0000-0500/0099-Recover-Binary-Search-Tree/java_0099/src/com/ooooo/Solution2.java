package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/8/8 14:44
 */
public class Solution2 {
  
  private TreeNode prev;
  private TreeNode node1, node2;
  
  private void dfs(TreeNode root) {
    if (root == null) return;
    dfs(root.left);
    if (prev != null && prev.val > root.val) {
      if (node1 == null) node1 = prev;
      node2 = root;
    }
    prev = root;
    dfs(root.right);
  }
  
  public void recoverTree(TreeNode root) {
    dfs(root);
    int tmp = node1.val;
    node1.val = node2.val;
    node2.val = tmp;
  }
  
  
  private static void test(TreeNode root) {
    Solution2 solution = new Solution2();
    solution.recoverTree(root);
    System.out.println();
  }
  
  public static void main(String[] args) {
    TreeNode root3 = new TreeNode(2);
    root3.left = new TreeNode(3);
    root3.right = new TreeNode(1);
    test(root3);
    
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(3);
    root.left.right = new TreeNode(2);
    test(root);
    
    TreeNode root2 = new TreeNode(3);
    root2.left = new TreeNode(1);
    root2.right = new TreeNode(4);
    root2.right.left = new TreeNode(2);
    test(root2);
  }
}
