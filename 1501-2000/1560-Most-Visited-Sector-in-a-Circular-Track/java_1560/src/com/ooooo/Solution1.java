package com.ooooo;

import java.util.ArrayList;
import java.util.List;

/**
 * 麻烦的写法
 * @author leizhijie
 * @since 2020/8/23 11:08
 */
public class Solution1 {
  
  int n = 0;
  int max_times = 0;
  
  private void count(int[] nums, int l, int r) {
    if (l > r) {
      count(nums, l, n + 1);
      count(nums, 1, r);
    } else {
      while (l < r) {
        nums[l]++;
        max_times = Math.max(max_times, nums[l]);
        l++;
      }
    }
  }
  
  public List<Integer> mostVisited(int n, int[] rounds) {
    this.n = n;
    int[] nums = new int[n + 1];
    for (int i = 0; i < rounds.length; i++) {
      if (i == rounds.length - 1) {
        nums[rounds[i]]++;
        max_times = Math.max(max_times, nums[rounds[i]]);
      } else {
        count(nums, rounds[i], rounds[i + 1]);
      }
    }
    
    List<Integer> ans = new ArrayList<>();
    for (int i = 1; i < nums.length; i++) {
      if (max_times == nums[i]) {
        ans.add(i);
      }
    }
    return ans;
  }
  
  public static void test(int n, int[] rounds) {
    Solution1 solution = new Solution1();
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
