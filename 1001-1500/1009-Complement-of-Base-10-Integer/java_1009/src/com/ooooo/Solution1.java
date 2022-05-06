package com.ooooo;

class Solution1 {
  
  public int bitwiseComplement(int N) {
    if (N == 0) return 1;
    int num = 0, size = Integer.bitCount(N);
    int i = 0;
    while (size > 0) {
      if ((N & 1) > 0) {
        size--;
      } else {
        num |= (1 << i);
      }
      i++;
      N >>= 1;
    }
    return num;
  }
  
  
  private static void test(int N) {
    Solution1 solution = new Solution1();
    int i = solution.bitwiseComplement(N);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(5); // 2
    test(7); // 0
    test(10); // 5
  }
}