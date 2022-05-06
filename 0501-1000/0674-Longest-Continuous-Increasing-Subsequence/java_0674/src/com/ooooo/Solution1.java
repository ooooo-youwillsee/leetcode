package com.ooooo;

class Solution1 {
  
  public int findLengthOfLCIS(int[] nums) {
    if (nums.length == 0) return 0;
    int count = 1, ans = 1;
    for (int i = 0; i < nums.length - 1; i++) {
      if (nums[i] >= nums[i + 1]) count = 0;
      count++;
      ans = Math.max(ans, count);
    }
    return ans;
  }
  
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int lengthOfLCIS = solution.findLengthOfLCIS(nums);
    System.out.println(lengthOfLCIS);
  }
  
  public static void main(String[] args) {
    test(new int[]{
        1, 3, 5, 4, 7
    }); // 3
  }
}

