package com.ooooo;

public class Solution2 {

  public int reverseBits(int num) {
    int bit = 32, len = 0, prevLen = 0, ans = 0;
    while (bit > 0) {
      len++;
      if ((num & 1) == 0) {
        len -= prevLen;
        prevLen = len;
      }
      num >>= 1;
      bit--;
      ans = Math.max(ans, len);
    }
    return ans;
  }

  private static void test(int num) {
    Solution2 solution = new Solution2();
    int ans = solution.reverseBits(num);
    System.out.println(ans);
  }

  public static void main(String[] args) {
    test(2147482622); // 30
    test(1775); // 8
    test(7); // 4
  }
}
