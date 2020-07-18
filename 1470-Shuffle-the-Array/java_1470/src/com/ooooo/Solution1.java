package com.ooooo;

class Solution1 {
  
  public int[] shuffle(int[] nums, int n) {
    int i = 0, j = n;
    int[] ans = new int[2 * n];
    int k = 0;
    while (i < n || j < nums.length) {
      ans[k++] = k % 2 != 0 ? nums[i++] : nums[j++];
    }
    return ans;
  }
  
  private static void test(int[] nums, int n) {
    Solution1 solution = new Solution1();
    int[] ans = solution.shuffle(nums, n);
    for (int i : ans) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[]{2, 5, 1, 3, 4, 7}, 3);
  }
  
}