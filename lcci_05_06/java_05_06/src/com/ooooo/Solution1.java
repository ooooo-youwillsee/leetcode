package com.ooooo;

class Solution1 {

  public int convertInteger(int A, int B) {
    int bits = 32, ans = 0;
    while (bits > 0) {
      if ((A & 1) != (B & 1)) ans++;
      A >>= 1;
      B >>= 1;
      bits--;
    }
    return ans;
  }

  private static void test(int A, int B) {
    Solution1 solution = new Solution1();
    int i = solution.convertInteger(A, B);
    System.out.println(i);
  }

  public static void main(String[] args) {
    test(29, 15);
    test(1, 2);
  }
}