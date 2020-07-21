package com.ooooo;

import java.util.ArrayList;
import java.util.List;

/**
 * @author leizhijie
 * @since 2020/7/21 10:22
 */
public class Solution1 {
  
  private List<TreeNode> genNodes(int l, int r) {
    List<TreeNode> treeNodes = new ArrayList<>();
    if (l > r) treeNodes.add(null);
    for (int i = l; i <= r; i++) {
      List<TreeNode> leftNodes = genNodes(l, i - 1);
      List<TreeNode> rightNodes = genNodes(i + 1, r);
      for (TreeNode leftNode : leftNodes) {
        for (TreeNode rightNode : rightNodes) {
          treeNodes.add(new TreeNode(i, leftNode, rightNode));
        }
      }
    }
    return treeNodes;
  }
  
  public List<TreeNode> generateTrees(int n) {
    if (n == 0) return new ArrayList<>();
    return genNodes(1, n);
  }
  
  private static void test(int n) {
    Solution1 solution = new Solution1();
    List<TreeNode> treeNodes = solution.generateTrees(n);
    for (TreeNode node : treeNodes) {
      System.out.print("");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(3);
  }
}
