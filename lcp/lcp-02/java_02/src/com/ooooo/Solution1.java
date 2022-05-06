package com.ooooo;

class Solution1 {
  
  /**
   * a1/b1 + 1/ (a2/b2)
   *
   * @return
   */
  public int[] plus(int a1, int b1, int a2, int b2) {
    if (a2 % b2 == 0) {
      b2 = a2 / b2;
      a2 = 1;
    } else {
      int temp = a2;
      a2 = b2;
      b2 = temp;
    }
    return new int[]{b2 * a1 + a2 * b1, b1 * b2};
  }
  
  private int gcd(int m, int n) {
    if (m < n) {
      int temp = n;
      n = m;
      m = temp;
    }
    return m % n == 0 ? n : gcd(n, m % n);
  }
  
  public int[] fraction(int[] cont) {
    int[] ans = new int[]{cont[cont.length - 1], 1};
    for (int i = cont.length - 2; i >= 0; i--) {
      ans = plus(cont[i], 1, ans[0], ans[1]);
    }
    int c = gcd(ans[0], ans[1]);
    return new int[]{ans[0] / c, ans[1] / c};
  }
  
  
  private static void test(int[] cont) {
    Solution1 solution = new Solution1();
    int[] fraction = solution.fraction(cont);
    System.out.println(String.format("[%d, %d]", fraction[0], fraction[1]));
  }
  
  public static void main(String[] args) {
    test(new int[]{
        3, 2, 0, 2
    }); // [13, 4]
  }
}