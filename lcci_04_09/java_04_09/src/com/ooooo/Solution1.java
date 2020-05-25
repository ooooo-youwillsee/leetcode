package com.ooooo;

import java.util.ArrayList;
import java.util.List;


/**
 * 用nodes来存放下一次可以选择的节点
 */
class Solution1 {

  private void dfs(List<TreeNode> nodes, List<Integer> nums) {
    if (nodes.isEmpty()) {
      ans.add(new ArrayList<>(nums));
      return;
    }
    for (int i = 0; i < nodes.size(); i++) {
      TreeNode node = nodes.get(i);
      nums.add(node.val);
      List<TreeNode> nextNodes = new ArrayList<>(nodes.size() + 1);
      for (int j = 0; j < nodes.size(); j++) {
        if (i != j) nextNodes.add(nodes.get(j));
      }
      if (node.left != null) nextNodes.add(node.left);
      if (node.right != null) nextNodes.add(node.right);
      dfs(nextNodes, nums);
      nums.remove(nums.size() - 1);
    }
  }

  private List<List<Integer>> ans = new ArrayList<>();

  public List<List<Integer>> BSTSequences(TreeNode root) {
    if (root == null) {
      ans.add(new ArrayList<>());
      return ans;
    }
    dfs(List.of(root), new ArrayList<>());
    return ans;
  }

  public static void main(String[] args) {
    Solution1 solution = new Solution1();
    TreeNode root = new TreeNode(1);
    solution.BSTSequences(root);
    System.out.println();
  }
}