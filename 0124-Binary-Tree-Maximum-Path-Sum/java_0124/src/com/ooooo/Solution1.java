package com.ooooo;

import java.util.HashMap;
import java.util.Map;

class Solution1 {
  
  private Map<TreeNode, Integer> map = new HashMap<>();
  
  private int getPathSum(TreeNode node) {
    if (map.containsKey(node)) return map.get(node);
    if (node == null) return 0;
    int sum = Math.max(getPathSum(node.left), getPathSum(node.right));
    sum = Math.max(sum + node.val, 0);
    map.put(node, sum);
    return sum;
  }
  
  
  public int maxPathSum(TreeNode root) {
    if (root == null) return 0;
    // 连通当前节点的值
    int sum = root.val + getPathSum(root.left) + getPathSum(root.right);
    int leftSum = Integer.MIN_VALUE, rightSum = Integer.MIN_VALUE;
    // 去看左右子树的最大值
    if (root.left != null) leftSum = Math.max(leftSum, maxPathSum(root.left));
    if (root.right != null) rightSum = Math.max(rightSum, maxPathSum(root.right));
    sum = Math.max(sum, leftSum);
    sum = Math.max(sum, rightSum);
    return sum;
  }
  
  private static void test(String[] nums) {
    Solution1 solution = new Solution1();
    int sum = solution.maxPathSum(new TreeNode(nums));
    System.out.println(sum);
  }
  
  /**
   *    1
   * -2  -3
   * 1 3 -2
   * -1
   * @param args
   */
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