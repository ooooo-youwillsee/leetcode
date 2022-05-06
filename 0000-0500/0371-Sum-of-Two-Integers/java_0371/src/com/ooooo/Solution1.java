package com.ooooo;

class Solution1 {
  
  /**
   * 15 + 16 = 31 ==> 21 + 10
   *
   * @param a
   * @param b
   * @return
   */
  public int getSum(int a, int b) {
    int c = a;
    while (b != 0) {
      c = a ^ b;
      b = (a & b) << 1;
      a = c;
    }
    return c;
  }
  
  private static void test(int a, int b) {
    Solution1 solution = new Solution1();
    int ans = solution.getSum(a, b);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    test(3, 3);
    test(1, 2);
  }
}