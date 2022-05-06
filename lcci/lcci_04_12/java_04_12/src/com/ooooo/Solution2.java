package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/5/17 10:39
 *
 * 遍历到每一层， 然后去判断路径相加是否为sum
 */
public class Solution2 {

  private int getDepth(TreeNode node) {
    if (node == null) return 0;
    return Math.max(getDepth(node.left), getDepth(node.right)) + 1;
  }

  private void dfs(TreeNode node, int sum, int level, int[] paths) {
    if (node == null) return;
    paths[level] = node.val;
    int t = 0;
    for (int i = level; i >= 0; i--) {
      t += paths[i];
      if (t == sum) count++;
    }
    dfs(node.left, sum, level + 1, paths);
    dfs(node.right, sum, level + 1, paths);
  }

  private int count = 0;

  public int pathSum(TreeNode root, int sum) {
    int depth = getDepth(root);
    int[] paths = new int[depth];
    dfs(root, sum, 0, paths);
    return count;
  }

}
