package com.ooooo;

import java.util.LinkedList;
import java.util.Queue;

/**
 * bfs
 * @author leizhijie
 * @since 2020/8/21 12:19
 */
public class Solution2 {
  
  
  public int minDepth(TreeNode root) {
    int level = 0;
    if (root == null) return level;
    Queue<TreeNode> q = new LinkedList<>();
    q.add(root);
    while (!q.isEmpty()) {
      level += 1;
      for (int i = 0, len = q.size(); i < len; i++) {
        TreeNode node = q.poll();
        // 左右节点都是null，说明是叶子节点
        if (node.left == null && node.right == null) {
          return level;
        }
        if (node.left != null) q.add(node.left);
        if (node.right != null) q.add(node.right);
      }
    }
    return level;
  }
  
  private static void test(TreeNode root) {
    Solution2 solution = new Solution2();
    int minDepth = solution.minDepth(root);
    System.out.println(minDepth);
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
