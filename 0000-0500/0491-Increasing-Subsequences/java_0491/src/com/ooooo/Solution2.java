package com.ooooo;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * @author leizhijie
 * @since 2020/8/26 11:11
 */
public class Solution2 {
  
  
  private final Set<List<Integer>> ans = new HashSet<>();
  
  private void dfs(int[] nums, int i, List<Integer> tmp) {
    if (tmp.size() >= 2) ans.add(new ArrayList<>(tmp));
    if (i == nums.length) return;
    for (int j = i; j < nums.length; j++) {
      if (!tmp.isEmpty() && tmp.get(tmp.size() - 1) > nums[j]) continue;
      tmp.add(nums[j]);
      dfs(nums, j + 1, tmp);
      tmp.remove(tmp.size() - 1);
    }
  }
  
  public List<List<Integer>> findSubsequences(int[] nums) {
    dfs(nums, 0, new ArrayList<>());
    return new ArrayList<>(ans);
  }
  
  private static void test(int[] nums) {
    Solution2 solution = new Solution2();
    List<List<Integer>> subsequences = solution.findSubsequences(nums);
    for (List<Integer> subsequence : subsequences) {
      for (Integer i : subsequence) {
        System.out.print(i + " ");
      }
      System.out.println();
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[]{4, 6, 7, 7});
  }
}
