package com.ooooo;

import java.util.HashMap;
import java.util.Map;

/**
 * @author leizhijie
 * @since 2020/8/5 10:38
 */
public class Solution2 {
  
  private Map<TreeNode, Integer> memo = new HashMap<>();
  
  public int rob(TreeNode root) {
    if (root == null) return 0;
    if (memo.containsKey(root)) return memo.get(root);
    int sum = root.val;
    if (root.left != null) {
      sum += rob(root.left.left) + rob(root.left.right);
    }
    if (root.right != null) {
      sum += rob(root.right.left) + rob(root.right.right);
    }
    sum = Math.max(sum, rob(root.left) + rob(root.right));
    memo.put(root, sum);
    return sum;
  }
  
  private static void test(TreeNode root) {
    Solution2 solution = new Solution2();
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
