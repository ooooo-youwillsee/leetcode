package com.ooooo;

class Solution1 {
  
  public int numWaterBottles(int numBottles, int numExchange) {
    // a 表示装满水的瓶子， b 表示空瓶子
    int count = numBottles, a = 0, b = numBottles;
    while (b >= numExchange) {
      a = b / numExchange;
      count += a;
      b = b - a*numExchange + a;
    }
    return count;
  }
  
  private static void test(int numBottles, int numExchange) {
    Solution1 solution = new Solution1();
    int i = solution.numWaterBottles(numBottles, numExchange);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(9, 3); // 13
    test(15, 4); // 19
    
  }
}