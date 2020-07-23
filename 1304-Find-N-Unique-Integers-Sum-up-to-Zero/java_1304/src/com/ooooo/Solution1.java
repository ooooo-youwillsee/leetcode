package com.ooooo;

class Solution1 {
  
  public int[] sumZero(int n) {
    int[] nums = new int[n];
    int i = 0;
    if (n % 2 == 1) nums[i++] = 0;
    for (int j = 1; j <= n/2; j++) {
      nums[i++] = j;
      nums[i++] = -j;
    }
    return nums;
  }
  
  private static void test(int n) {
    Solution1 solution = new Solution1();
    int[] ints = solution.sumZero(n);
    for (int anInt : ints) {
      System.out.print(anInt + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(5);
  }
}