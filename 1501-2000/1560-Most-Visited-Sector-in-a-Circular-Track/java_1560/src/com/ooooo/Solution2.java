package com.ooooo;

import java.util.ArrayList;
import java.util.List;

/**
 * 模拟
 *
 * @author leizhijie
 * @since 2020/8/23 17:39
 */
public class Solution2 {
  
  public List<Integer> mostVisited(int n, int[] rounds) {
    int[] nums = new int[n + 1];
    int max_times = 0, i = 0;
    for (; i < rounds.length - 1; i++) {
      int l = rounds[i], r = rounds[i + 1];
      while (l != r) {
        nums[l]++;
        max_times = Math.max(max_times, nums[l]);
        l++;
        if (l == n + 1) l = 1;
      }
    }
    nums[rounds[i]]++;
    max_times = Math.max(max_times, nums[rounds[i]]);
    
    List<Integer> ans = new ArrayList<>();
    for (int k = 1; k < nums.length; k++) {
      if (max_times == nums[k]) {
        ans.add(k);
      }
    }
    return ans;
  }
  
  public static void test(int n, int[] rounds) {
    Solution2 solution = new Solution2();
    List<Integer> list = solution.mostVisited(n, rounds);
    for (Integer i : list) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(2, new int[]{2, 1, 2, 1, 2, 1, 2, 1, 2});
    test(4, new int[]{1, 3, 1, 2});
  }
}
