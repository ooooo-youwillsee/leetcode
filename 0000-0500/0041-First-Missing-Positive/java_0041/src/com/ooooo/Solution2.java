package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/6/27 16:27
 */
public class Solution2 {

  private void swap(int[] nums, int a, int b) {
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
  }

  public int firstMissingPositive(int[] nums) {
    for (int i = 0; i < nums.length; i++) {
      while (nums[i] > 0 && nums[i] - 1 <= nums.length - 1
          && nums[nums[i] - 1] != nums[i]) {
        swap(nums, i, nums[i] - 1);
      }
    }
    int i = 0;
    for (; i < nums.length; i++) {
      if (nums[i] != i + 1) return i + 1;
    }
    return i + 1;
  }

  private static void test(int[] nums) {
    Solution2 solution = new Solution2();
    int n = solution.firstMissingPositive(nums);
    System.out.println(n);
  }

  public static void main(String[] args) {
    test(new int[]{1, 1}); // 2
    test(new int[]{1}); // 2
    test(new int[]{3, 4, -1, 1}); // 2
    test(new int[0]); // 1
    test(new int[]{1, 2, 0});  // 3
    test(new int[]{7, 8, 9, 11, 12}); // 1
  }
}
