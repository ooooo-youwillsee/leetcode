package com.ooooo;

class Solution1 {
  
  public int rangeBitwiseAnd(int m, int n) {
    if (m == n) return m;
    int ans = 0;
    for (int j = 0; j < 32 && m > 0 && n > 0; j++) {
      boolean flag = true;
      for (int i = m; i <= n; i++) {
        if ((i & 1) == 0) {
          flag = false;
          break;
        }
      }
      if (flag)
        ans = ans | (1 << j);
      m >>= 1;
      n >>= 1;
    }
    return ans;
  }
  
  private static void test(int m, int n) {
    Solution1 solution = new Solution1();
    int i = solution.rangeBitwiseAnd(m, n);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(5, 7); // 4
    test(0, 1); // 0
  }
}