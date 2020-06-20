package com.ooooo;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * set 去重
 * 排序
 */
class Solution1 {
  
  public int longestConsecutive(int[] nums) {
    if (nums == null || nums.length == 0) return 0;
    Set<Integer> set = new HashSet<>(nums.length);
    List<Integer> list = new ArrayList<>(nums.length);
    for (int num : nums) {
      if (!set.contains(num)) {
        list.add(num);
      }
      set.add(num);
    }
    Collections.sort(list);
    int count = 1, ans = 1;
    for (int i = 0; i < list.size() - 1; i++) {
      if (list.get(i + 1) - list.get(i) == 1) {
        count++;
        ans = Math.max(ans, count);
      } else {
        count = 1;
      }
    }
    return ans;
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int n = solution.longestConsecutive(nums);
    System.out.println(n);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 2, 0, 1}); // 3
    test(new int[]{100, 4, 200, 1, 3, 2}); // 4
    test(new int[]{100, 4, 200, 3, 2, 6, 7, 8, 9, 10}); // 3
  }
}