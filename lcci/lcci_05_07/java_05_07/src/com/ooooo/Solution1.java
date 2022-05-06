package com.ooooo;

class Solution1 {

  public int exchangeBits(int num) {
    int bits = 32, ans = 0, n = 0;
    for (int i = 0; i < bits; i++) {
      n <<= 1;
      if ((i & 1) == 1) n += 1;
    }
    ans = (num >> 1) & n; // odd
    ans |= (num << 1) & (~n); // even
    return ans;
  }

  private static void test(int num) {
    Solution1 solution = new Solution1();
    int i = solution.exchangeBits(num);
    System.out.println(i);
    // 000110100101
    // 000011010010
    // 001101001010
    // 001001011010
  }

  public static void main(String[] args) {
    test(2); // 1
    test(3); // 3
  }
}