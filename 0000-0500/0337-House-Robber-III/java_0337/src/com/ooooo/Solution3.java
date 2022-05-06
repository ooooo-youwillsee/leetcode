package com.ooooo;

/**
 *
 * 树状dp -> 后序遍历
 * @author leizhijie
 * @since 2020/8/5 11:51
 */
public class Solution3 {
  
  
  public int[] robInternal(TreeNode root) {
    int[] sum = {0, 0};
    if (root == null) return sum;
    int[] left = robInternal(root.left);
    int[] right = robInternal(root.right);
    sum[0] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
    sum[1] = root.val + left[0] + right[0];
    return sum;
  }
  
  public int rob(TreeNode root) {
    int[] sum = robInternal(root);
    return Math.max(sum[0], sum[1]);
  }
  
  private static void test(TreeNode root) {
    Solution3 solution = new Solution3();
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
