package com.ooooo;

import java.util.ArrayList;
import java.util.List;

/**
 * @author leizhijie
 * @since 2020/5/25 11:25
 */
public class Solution2 {

  public List<List<Integer>> BSTSequences(TreeNode root) {
    List<List<Integer>> ans = new ArrayList<>();
    if (root == null) {
      ans.add(new ArrayList<>());
      return ans;
    }
    List<List<Integer>> left = BSTSequences(root.left);
    List<List<Integer>> right = BSTSequences(root.right);
    // 判断 left 和 right 是否为空，也就是说可能出现[[]]。
    if (left.size() == 1 && left.get(0).size() == 0) {
      ans.addAll(right);
    } else if (right.size() == 1 && right.get(0).size() == 0) {
      ans.addAll(left);
    } else {
      for (List<Integer> l : left) {
        for (List<Integer> r : right) {
          merge(l, 0, r, 0, new ArrayList<>(), ans);
        }
      }
    }
    for (List<Integer> nums : ans) {
      nums.add(0, root.val);
    }
    return ans;
  }

  public List<List<Integer>> BSTSequences2(TreeNode root) {
    List<List<Integer>> ans = new ArrayList<>();
    if (root == null) {
      ans.add(new ArrayList<>());
      return ans;
    }
    List<List<Integer>> left = BSTSequences(root.left);
    List<List<Integer>> right = BSTSequences(root.right);
    for (List<Integer> l : left) {
      for (List<Integer> r : right) {
        List<Integer> nums = new ArrayList<>();
        nums.add(root.val);
        merge(l, 0, r, 0, nums, ans);
      }
    }
    return ans;
  }

  private void merge(List<Integer> l, int i, List<Integer> r, int j, List<Integer> nums,
      List<List<Integer>> ans) {
    if (i >= l.size() && j >= r.size()) {
      ans.add(new ArrayList<>(nums));
      return;
    }
    if (i < l.size()) {
      nums.add(l.get(i));
      merge(l, i + 1, r, j, nums, ans);
      nums.remove(nums.size() - 1);
    }
    if (j < r.size()) {
      nums.add(r.get(j));
      merge(l, i, r, j + 1, nums, ans);
      nums.remove(nums.size() - 1);
    }
  }

  public static void main(String[] args) {
    Solution2 solution = new Solution2();
    TreeNode root = new TreeNode(1);
    List<List<Integer>> ans = solution.BSTSequences(root);
    System.out.println();
  }

}
