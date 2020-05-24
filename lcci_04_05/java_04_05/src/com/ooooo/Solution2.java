package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/5/15 10:22
 */
public class Solution2 {

  private double x = (double) Integer.MIN_VALUE - 1;

  public boolean isValidBST(TreeNode root) {
    if (root == null) return true;
    if (!isValidBST(root.left)) return false;
    if (x >= root.val) return false;
    x = root.val;
    return isValidBST(root.right);
  }

  public static void main(String[] args) {
    Solution2 solution = new Solution2();
    System.out.println(solution.isValidBST(new TreeNode(0)));
  }
}
