package com.ooooo;

import java.util.ArrayList;
import java.util.List;

class Solution1 {

  private void dfs(int[] nums, int i, List<Integer> data) {
    ans.add(new ArrayList<>(data));
    for (int j = i; j < nums.length; j++) {
      data.add(nums[j]);
      dfs(nums, j + 1, data);
      data.remove(data.size() - 1);
    }
  }

  private List<List<Integer>> ans = new ArrayList<>();

  public List<List<Integer>> subsets(int[] nums) {
    dfs(nums, 0, new ArrayList<>());
    return ans;
  }

  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    List<List<Integer>> subsets = solution.subsets(nums);
    System.out.println("=".repeat(10));
    for (List<Integer> subset : subsets) {
      for (Integer n : subset) {
        System.out.print(n + " ");
      }
      System.out.println();
    }
    System.out.println("=".repeat(10));
  }

  public static void main(String[] args) {
    test(new int[]{1, 2, 3});
  }
}