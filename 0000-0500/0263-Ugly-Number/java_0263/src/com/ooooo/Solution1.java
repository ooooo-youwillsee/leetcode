package com.ooooo;

class Solution1 {
  
  private int divide(int num, int n) {
    while (num % n == 0) {
      num /= n;
    }
    return num;
  }
  
  public boolean isUgly(int num) {
    if (num == 0) return false;
    num = divide(num, 2);
    num = divide(num, 3);
    num = divide(num, 5);
    return num == 1;
  }
  
  private static void test(int num) {
    Solution1 solution = new Solution1();
    boolean ugly = solution.isUgly(num);
    System.out.println(ugly);
  }
  
  public static void main(String[] args) {
    test(6);
  }
}