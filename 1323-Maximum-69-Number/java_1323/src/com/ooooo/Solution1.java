package com.ooooo;

class Solution1 {
  
  public int maximum69Number(int num) {
    int sum = 0, n = 1000;
    while (num > 0) {
      int a = num / n;
      if (a == 6) {
        return num % n + n * 9 + sum;
      }
      sum += a * n;
      num %= n;
      n /= 10;
    }
    return sum;
  }
  
  private static void test(int num) {
    Solution1 solution = new Solution1();
    int i = solution.maximum69Number(num);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(9669);
    test(9996);
    test(9999);
  }
}