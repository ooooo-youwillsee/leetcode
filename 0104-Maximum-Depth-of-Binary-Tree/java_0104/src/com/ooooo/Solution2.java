package com.ooooo;

import java.util.LinkedList;
import java.util.Queue;

/**
 * @author leizhijie
 * @since 2020/7/28 14:19
 */
public class Solution2 {
  
  public int maxDepth(TreeNode root) {
    if (root == null) return 0;
    Queue<TreeNode> q = new LinkedList<>();
    q.add(root);
    int level = 0;
    while(!q.isEmpty()) {
      level++;
      for (int i = 0, size = q.size(); i < size; i++) {
        TreeNode node = q.poll();
        if (node.left != null) q.add(node.left);
        if (node.right != null) q.add(node.right);
      }
    }
    return level;
  }
  
  
  public static void main(String[] args) {
    TreeNode root = new TreeNode(3);
    root.left = new TreeNode(9);
    root.right = new TreeNode(20);
    root.right.left = new TreeNode(15);
    root.right.right = new TreeNode(7);
    Solution2 solution = new Solution2();
    int i = solution.maxDepth(root);
    System.out.println(i);
  }
}
