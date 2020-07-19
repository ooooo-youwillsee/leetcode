package com.ooooo;

class Solution1 {
  
  public int numberOfSteps(int num) {
    int count  =0;
    while(num >0) {
      count++;
      num = num % 2 == 0 ? num / 2 : num - 1;
    }
    return count;
  }
  
  private static void test(int num) {
    Solution1 solution = new Solution1();
    int i = solution.numberOfSteps(num);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(14); // 6
    test(123); // 12
  }
}