package com.ooooo;

class Solution1 {
  
  public int minCostToMoveChips(int[] chips) {
    int even = 0, odd = 0;
    for (int chip : chips) {
      if (chip %2 == 0) even++;
      else odd++;
    }
    return Math.min(even, odd);
  }
  
  
  private static void test(int[] chips) {
    Solution1 solution = new Solution1();
    int i = solution.minCostToMoveChips(chips);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{2, 2, 2, 3, 3}); // 2
  }
}