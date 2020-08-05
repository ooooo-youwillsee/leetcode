package com.ooooo;

/**
 * dfs
 * @author leizhijie
 * @since 2020/8/5 10:03
 */
public class Solution1 {
  
  private int dfs(TreeNode root, boolean rob) {
    if (root == null) return 0;
    int sum = 0;
    if (!rob) {
      sum = root.val + dfs(root.left, true) + dfs(root.right, true);
    }
    sum = Math.max(sum, dfs(root.left, false) + dfs(root.right, false));
    return sum;
  }
  
  public int rob(TreeNode root) {
    return dfs(root, false);
  }
  
  private static void test(TreeNode root) {
    Solution1 solution = new Solution1();
    int rob = solution.rob(root);
    System.out.println(rob);
  }
  
  public static void main(String[] args) {
    TreeNode root = new TreeNode(3);
    root.left = new TreeNode(4);
    root.right = new TreeNode(5);
    root.left.left = new TreeNode(1);
    root.left.right = new TreeNode(3);
    root.right.right = new TreeNode(1);
    test(root); // 9
  }
}
