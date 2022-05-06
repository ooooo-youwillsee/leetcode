package com.ooooo;

class Solution1 {
  
  public int minStartValue(int[] nums) {
    int ans = 1, sum = 0;
    for (int num : nums) {
      sum += num;
      ans = Math.max(ans, 1 - sum);
    }
    return ans;
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    int i = solution.minStartValue(nums);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{
        -3, 2, -3, 4, 2
    }); // 5
    
    test(new int[]{
        1, 2
    }); // 1
    
    test(new int[]{
        1, -2, -3
    }); // 5
  }
  
  
}