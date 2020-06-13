package com.ooooo;

class Solution1 {
  
  public int maxProfit(int[] prices) {
    if (prices == null || prices.length == 0) return 0;
    int profit = 0, min = prices[0];
    for (int i = 1; i < prices.length; i++) {
      if (prices[i] < min) min = prices[i];
      profit = Math.max(profit, prices[i] - min);
    }
    return profit;
  }
  
  private static void test(int[] prices) {
    Solution1 solution = new Solution1();
    int ans = solution.maxProfit(prices);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    test(new int[]{7, 1, 5, 3, 6, 4}); // 5
    test(new int[]{7, 6, 4, 3, 1}); // 0
  }
}