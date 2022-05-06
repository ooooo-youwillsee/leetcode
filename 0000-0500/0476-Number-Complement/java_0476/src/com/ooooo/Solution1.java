package com.ooooo;

class Solution1 {
  
  public int findComplement(int num) {
    int count_1 = 0, a = num;
    while (a > 0) {
      a = a & (a - 1);
      count_1++;
    }
    int bit = 0, b = num;
    while (count_1 > 0) {
      if ((b & 1) > 0) count_1--;
      b >>= 1;
      bit++;
    }
    return (~num) & ((1 << bit) - 1);
  }
  
  private static void test(int num) {
    Solution1 solution = new Solution1();
    int complement = solution.findComplement(num);
    System.out.println(complement);
  }
  
  public static void main(String[] args) {
    test(5); // 2
    test(1); // 0
    // 00000101
    // 11111010
    System.out.println(~5);
  }
}