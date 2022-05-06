package com.ooooo;

import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Set;

class Solution1 {
  
  public int thirdMax(int[] nums) {
    PriorityQueue<Integer> q = new PriorityQueue<>(3);
    Set<Integer> set = new HashSet<>();
    for (int num : nums) {
      if (set.contains(num)) continue;
      set.add(num);
      if (q.size() < 3) {
        q.add(num);
      } else {
        if (q.peek() <= num) {
          q.poll();
          q.add(num);
        }
      }
    }
    if (q.size() < 3) {
      while (!q.isEmpty()) {
        if (q.size() == 1) return q.poll();
        q.poll();
      }
    }
    return q.poll();
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int n = solution.thirdMax(nums);
    System.out.println(n);
  }
  
  public static void main(String[] args) {
    test(new int[]{2, 2, 3, 1});
    test(new int[]{2, 2, 3, 1, 4, 5});
    test(new int[]{3, 2, 1});
    test(new int[]{2, 1});
  }
}