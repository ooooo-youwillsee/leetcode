package com.ooooo;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * 暴力dfs
 */
class Solution1 {
  
  private List<List<Integer>> nums_list = new ArrayList<>();
  private Set<String> set = new HashSet<>();
  
  private void dfs(int[] nums, int i) {
    if (i == nums.length) return;
    for (int j = 0, len = nums_list.size(); j < len; j++) {
      List<Integer> list = nums_list.get(j);
      if (nums[i] >= list.get(list.size() - 1)) {
        nums_list.add(new ArrayList<>(list));
        list.add(nums[i]);
      }
    }
    List<Integer> tmp = new ArrayList<>();
    tmp.add(nums[i]);
    nums_list.add(tmp);
    dfs(nums, i + 1);
  }
  
  public List<List<Integer>> findSubsequences(int[] nums) {
    dfs(nums, 0);
    
    List<List<Integer>> ret = new ArrayList<>();
    for (List<Integer> an : nums_list) {
      if (an.size() <= 1) continue;
      StringBuilder sb = new StringBuilder();
      for (Integer i : an) {
        sb.append(i).append(",");
      }
      String num_str = sb.toString();
      if (!set.contains(num_str)) {
        ret.add(an);
        set.add(num_str);
      }
    }
    return ret;
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
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