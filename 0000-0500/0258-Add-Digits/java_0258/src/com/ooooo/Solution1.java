package com.ooooo;

class Solution1 {
  
  private int getSumDigits(int num) {
    int sum = 0;
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }
    return sum;
  }
  
  public int addDigits(int num) {
    if (num >= 0 && num < 10) return num;
    return addDigits(getSumDigits(num));
  }
  
  private static void test(int num) {
    Solution1 solution = new Solution1();
    int ans = solution.addDigits(num);
    System.out.println(num+ "=>" + ans);
  }
  
  public static void main(String[] args) {
    test(38);
    test(22);
    for (int i = 0; i < 120; i++) {
      test(i);
    }
  }
}