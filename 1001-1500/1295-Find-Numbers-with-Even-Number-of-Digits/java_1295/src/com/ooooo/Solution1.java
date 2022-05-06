package com.ooooo;

class Solution1 {
  
  public int findNumbers(int[] nums) {
    int count = 0;
    for (int num : nums) {
      if (String.valueOf(num).length() % 2 == 0) count++;
    }
    return count;
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int i = solution.findNumbers(nums);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{12, 345, 2, 6, 7896}); // 2
  }
}