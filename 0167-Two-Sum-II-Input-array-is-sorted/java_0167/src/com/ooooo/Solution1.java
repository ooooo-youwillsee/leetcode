package com.ooooo;

class Solution1 {
  
  public int[] twoSum(int[] numbers, int target) {
    int l = 0, r = numbers.length - 1;
    while (l < r) {
      int sum = numbers[l] + numbers[r];
      if (sum == target) {
        return new int[]{l + 1, r + 1};
      } else if (sum < target) {
        l++;
      } else {
        r--;
      }
    }
    return null;
  }
  
  private static void test(int[] nums, int target) {
    Solution1 solution = new Solution1();
    int[] indexes = solution.twoSum(nums, target);
    System.out.println(indexes[0] + " " + indexes[1]);
  }
  
  public static void main(String[] args) {
    test(new int[]{2, 7, 11, 15}, 9); // 1,2
  }
}