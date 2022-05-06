package com.ooooo;

/**
 * binary search
 *
 * @author leizhijie
 * @since 2020/7/25 15:54
 */
public class Solution2 {
  
  
  public int splitArray(int[] nums, int m) {
    long l = 0, r = 0;
    for (int num : nums) {
      r += num;
      if (l < num) l = num;
    }
    while (l < r) {
      long mid = l + (r - l) / 2;
      int count = 1;
      int tmp = 0;
      for (int num : nums) {
        if (tmp + num > mid) {
          tmp = 0;
          count++;
        }
        tmp += num;
      }
      if (count <= m) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return (int) l;
  }
  
  private static void test(int[] nums, int m) {
    Solution2 solution = new Solution2();
    int i = solution.splitArray(nums, m);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{7, 2, 5, 10, 8}, 2);
    test(new int[]{1, 2147483647}, 2);
  }
}
