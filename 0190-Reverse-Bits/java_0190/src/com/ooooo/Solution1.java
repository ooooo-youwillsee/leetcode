package com.ooooo;

public class Solution1 {
  
  // you need treat n as an unsigned value
  public int reverseBits(int n) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
      ans <<= 1;
      if ((n & 1) == 1) ans |= 1;
      n >>= 1;
    }
    return ans;
  }
  
  private static void test(int n) {
    Solution1 solution = new Solution1();
    int ans = solution.reverseBits(n);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    test(43261596); // 964176192
    //test(4294967293); // 3221225471
  }
}