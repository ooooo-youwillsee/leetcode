package com.ooooo;

import java.util.HashSet;
import java.util.Set;

/**
 * @author leizhijie
 * @since 2020/6/20 12:48
 */
public class Solution2 {
  
  
  private int dfs(int v) {
    if (!set.contains(v) || marked.contains(v)) return 0;
    marked.add(v);
    return 1 + dfs(v + 1) + dfs(v - 1);
  }
  
  private Set<Integer> marked = new HashSet<>();
  private Set<Integer> set = new HashSet<>();
  
  public int longestConsecutive(int[] nums) {
    if (nums == null || nums.length == 0) return 0;
    for (int num : nums) {
      set.add(num);
    }
    int ans = 1;
    for (int num : nums) {
      ans = Math.max(ans, dfs(num));
    }
    return ans;
  }
  
  private static void test(int[] nums) {
    Solution2 solution = new Solution2();
    int n = solution.longestConsecutive(nums);
    System.out.println(n);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 2, 0, 1}); // 3
    test(new int[]{100, 4, 200, 1, 3, 2}); // 4
    test(new int[]{100, 4, 200, 3, 2, 6, 7, 8, 9, 10}); // 3
  }
}
