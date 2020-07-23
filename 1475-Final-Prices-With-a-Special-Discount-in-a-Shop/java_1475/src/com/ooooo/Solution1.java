package com.ooooo;

class Solution1 {
  
  public int[] finalPrices(int[] prices) {
    int[] discount = new int[prices.length];
    for (int i = 0; i < prices.length; i++) {
      discount[i] = prices[i];
      for (int j = i+1; j < prices.length; j++) {
        if (prices[j] <= prices[i]) {
          discount[i] = prices[i] - prices[j];
          break;
        }
      }
    }
    return discount;
  }
  
  private static void test(int[] prices) {
    Solution1 solution = new Solution1();
    int[] ints = solution.finalPrices(prices);
    for (int anInt : ints) {
      System.out.print(anInt + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[]{8, 4, 6, 2, 3});
  }
}