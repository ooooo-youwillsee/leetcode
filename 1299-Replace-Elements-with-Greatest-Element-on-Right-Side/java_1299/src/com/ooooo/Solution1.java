package com.ooooo;

class Solution1 {
  
  public int[] replaceElements(int[] arr) {
    int max = -1;
    int[] ans = new int[arr.length];
    for (int i = arr.length - 1; i >= 0; i--) {
      ans[i] = max;
      max = Math.max(max, arr[i]);
    }
    return ans;
  }
  
  private static void test(int[] arr) {
    Solution1 solution = new Solution1();
    int[] nums = solution.replaceElements(arr);
    for (int num : nums) {
      System.out.print(num + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[]{17, 18, 5, 4, 6, 1}); // 18,6,6,6,1,-1
  }
}