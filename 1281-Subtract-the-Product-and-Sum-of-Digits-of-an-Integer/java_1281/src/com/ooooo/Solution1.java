package com.ooooo;

class Solution1 {
  
  public int subtractProductAndSum(int n) {
    int sum = 0, product = 1;
    while (n > 0) {
      sum += n % 10;
      product *= n % 10;
      n /= 10;
    }
    return product - sum;
  }
  
  private static void test(int n) {
    Solution1 solution = new Solution1();
    int i = solution.subtractProductAndSum(n);
    System.out.println(i);
  }
  
  
  public static void main(String[] args) {
    test(234); // 15
    test(4421); // 21
  }
}