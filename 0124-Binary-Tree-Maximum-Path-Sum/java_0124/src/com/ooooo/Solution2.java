package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/6/21 09:39
 */
public class Solution2 {
  
  private int sum = Integer.MIN_VALUE;
  
  private int getPathSum(TreeNode node) {
    if (node == null) return 0;
    int left = Math.max(0, getPathSum(node.left));
    int right = Math.max(0, getPathSum(node.right));
    sum = Math.max(sum, node.val + left + right);
    return Math.max(left, right) + node.val;
  }
  
  public int maxPathSum(TreeNode root) {
    getPathSum(root);
    return sum;
  }
  
  private static void test(String[] nums) {
    Solution2 solution = new Solution2();
    int sum = solution.maxPathSum(new TreeNode(nums));
    System.out.println(sum);
  }
  
  
  public static void main(String[] args) {
    test(new String[]{"1", "-2", "-3", "1", "3", "-2", null, "-1"});
    test(new String[]{"8", "9", "-6", null, null, "5", "9"});
    test(new String[]{"-2", "-1"});
    test(new String[]{"-3"});
    test(new String[]{"-3", "-2", "6"});
    test(new String[]{"1", "2", "3"});
    test(new String[]{"-10", "9", "20", null, null, "15", "7"});
  }
}
