package com.ooooo;

/**
 * 暴力破解
 */
class Solution1 {

  public int[] findClosedNumbers(int num) {
    int bits_count = Integer.bitCount(num);
    int small = num - 1, big = num + 1;
    for (; small >= 1; small--) {
      if (Integer.bitCount(small) == bits_count) break;
    }
    for (; big <= Integer.MAX_VALUE; big++) {
      if (Integer.bitCount(big) == bits_count) break;
    }
    return new int[]{big == Integer.MAX_VALUE ? -1 : big, small == 0 ? -1 : small};
  }


  private static void test(int num) {
    Solution1 solution = new Solution1();
    int[] ans = solution.findClosedNumbers(num);
    System.out.println(String.format("[%d, %d]", ans[0], ans[1]));
  }

  public static void main(String[] args) {
    test(1837591841); // [1837591842, 1837591832]
    test(1);  // [2, -1]
    test(2);  // [4, 1]
  }
}