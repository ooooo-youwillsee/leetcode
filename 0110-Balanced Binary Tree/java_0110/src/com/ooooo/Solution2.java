package com.ooooo;

import java.util.HashMap;
import java.util.Map;

/**
 * @author leizhijie
 * @since 2020/8/17 20:48
 */
public class Solution2 {
  
  private boolean isBalanced = true;
  
  private int getH(TreeNode root) {
    if (root == null || !isBalanced) return 0;
    int l_h = getH(root.left);
    int r_h = getH(root.right);
    if (Math.abs(l_h - r_h) > 1) {
      isBalanced = false;
    }
    return Math.max(l_h, r_h) + 1;
  }
  
  public boolean isBalanced(TreeNode root) {
    getH(root);
    return isBalanced;
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
