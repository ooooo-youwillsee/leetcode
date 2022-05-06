package com.ooooo;

import java.util.Arrays;

/**
 * @author leizhijie
 * @since 2020/6/27 11:54
 */
public class Solution2 {

  public int threeSumClosest(int[] nums, int target) {
    Arrays.sort(nums);
    int diff = Integer.MAX_VALUE, ans = 0;
    for (int i = 0, len = nums.length; i < len; i++) {
      int l = i + 1, r = len - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum == target) {
          return sum;
        } else if (sum < target) {
          l++;
        } else {
          r--;
        }
        int sub = Math.abs(sum - target);
        if (sub < diff) {
          diff = sub;
          ans = sum;
        }
      }
    }
    return ans;
  }

  private static void test(int[] nums, int target) {
    Solution2 solution = new Solution2();
    int num = solution.threeSumClosest(nums, target);
    System.out.println(num);
  }

  public static void main(String[] args) {
    test(new int[]{-1, 2, 1, -4}, 1);
  }
}
