package com.ooooo;

class Solution1 {
  
  public int minCount(int[] coins) {
    int count = 0;
    for (int coin : coins) {
      count += (coin + 1) / 2;
    }
    return count;
  }
  
  private static void test(int[] coins) {
    Solution1 solution = new Solution1();
    int i = solution.minCount(coins);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{2, 3, 10}); // 8
  }
}