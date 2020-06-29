package com.ooooo;

import java.util.PriorityQueue;

/**
 * heap
 */
class Solution1 {

  public int findKthLargest(int[] nums, int k) {
    PriorityQueue<Integer> q = new PriorityQueue<>(k);
    for (int num : nums) {
      if (q.size() < k) {
        q.add(num);
      } else if (q.peek().intValue() < num) {
        q.poll();
        q.add(num);
      }
    }
    return q.peek();
  }

  private static void test(int[] nums, int k) {
    Solution1 solution = new Solution1();
    int num = solution.findKthLargest(nums, k);
    System.out.println(num);
  }

  public static void main(String[] args) {
    test(new int[]{3, 2, 1, 5, 6, 4}, 2); // 5
    test(new int[]{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4); // 4
  }
}