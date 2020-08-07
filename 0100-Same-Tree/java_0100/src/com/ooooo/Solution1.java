package com.ooooo;

class Solution1 {
  
  public boolean isSameTree(TreeNode p, TreeNode q) {
    if (p == null && q == null) return true;
    if (p == null || q == null) return false;
    return p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
  }
  
  private static void test(TreeNode p, TreeNode q) {
    Solution1 solution = new Solution1();
    boolean sameTree = solution.isSameTree(p, q);
    System.out.println(sameTree);
  }
  
  public static void main(String[] args) {
    TreeNode p = new TreeNode(1);
    p.left = new TreeNode(2);
    TreeNode q = new TreeNode(1);
    q.right = new TreeNode(2);
    test(p, q);
  }
}