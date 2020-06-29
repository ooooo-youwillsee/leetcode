package com.ooooo;

import java.util.PriorityQueue;

/**
 * @author leizhijie
 * @since 2020/6/29 11:53
 * <p>
 * partition
 */
public class Solution2 {

  private void swap(int[] nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }

  private int partition(int[] nums, int l, int r) {
    int i = l, j = l + 1, num = nums[l];
    while (j <= r) {
      if (nums[j] >= num) {
        swap(nums, j, i + 1);
        i++;
      }
      j++;
    }
    swap(nums, i, l);
    return i;
  }

  public int findKthLargest(int[] nums, int k) {
    int l = 0, r = nums.length - 1;
    while (l <= r) {
      int p = partition(nums, l, r);
      if (p == k - 1) {
        return nums[p];
      } else if (p < k - 1) {
        l = p + 1;
      } else {
        r = p - 1;
      }
    }
    return -1;
  }

  private static void test(int[] nums, int k) {
    Solution2 solution = new Solution2();
    int num = solution.findKthLargest(nums, k);
    System.out.println(num);
  }

  public static void main(String[] args) {
    test(new int[]{3, 2, 1, 5, 6, 4}, 2); // 5
    test(new int[]{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4); // 4
  }
}
