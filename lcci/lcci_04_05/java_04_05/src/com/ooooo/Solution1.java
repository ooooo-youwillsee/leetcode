package com.ooooo;

import java.util.ArrayList;
import java.util.List;

class Solution1 {


  private void dfs(TreeNode node) {
    if (node == null) return;
    dfs(node.left);
    data.add(node.val);
    dfs(node.right);
  }

  private List<Integer> data = new ArrayList<>();

  public boolean isValidBST(TreeNode root) {
    dfs(root);
    for (int i = 1, len = data.size(); i < len; i++) {
      if (data.get(i - 1).compareTo(data.get(i)) >= 0) return false;
    }
    return true;
  }
}