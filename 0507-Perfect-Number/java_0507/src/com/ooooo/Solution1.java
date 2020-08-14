package com.ooooo;

class Solution1 {
  
  public boolean checkPerfectNumber(int num) {
    if (num == 1) return false;
    int sum = 1, n = (int) Math.sqrt(num) + 1;
    for (int i = 2; i < n; i++) {
      if (num % i == 0) {
        sum += i + (num == i * i ? 0 : num / i);
      }
    }
    return sum == num;
  }
  
  
  private static void test(int num) {
    Solution1 solution = new Solution1();
    System.out.println(solution.checkPerfectNumber(num));
  }
  
  
  public static void main(String[] args) {
    test(6);
    test(28);
  }
}