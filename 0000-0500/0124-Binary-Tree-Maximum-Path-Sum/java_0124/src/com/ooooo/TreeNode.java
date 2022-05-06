package com.ooooo;

import java.util.LinkedList;
import java.util.Queue;

public class TreeNode {
  
  int val;
  TreeNode left;
  TreeNode right;
  
  TreeNode(int x) { val = x; }
  
  TreeNode(String[] nums) {
    if (nums == null || nums.length == 0) return;
    this.val = Integer.parseInt(nums[0]);
    this.left = this.right = null;
    Queue<TreeNode> q = new LinkedList<>();
    q.add(this);
    for (int i = 1; i < nums.length; i += 2) {
      TreeNode node = q.poll();
      if (nums[i] != null) {
        node.left = new TreeNode(Integer.parseInt(nums[i]));
      }
      if (i + 1 >= nums.length) return;
      if (nums[i + 1] != null){
        node.right = new TreeNode(Integer.parseInt(nums[i + 1]));
      }
      if (node.left != null) q.add(node.left);
      if (node.right != null) q.add(node.right);
    }
  }
}