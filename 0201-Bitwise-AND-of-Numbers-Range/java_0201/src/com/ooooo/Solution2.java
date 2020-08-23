package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/8/23 18:42
 */
public class Solution2 {
  
  
  public int rangeBitwiseAnd(int m, int n) {
    if (m == n) return m;
    int ans = 0;
    while (m < n) {
      m >>= 1;
      n >>= 1;
      ans++;
    }
    return m << ans;
  }
  
  private static void test(int m, int n) {
    Solution2 solution = new Solution2();
    int i = solution.rangeBitwiseAnd(m, n);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(5, 7); // 4
    test(0, 1); // 0
  }
  
}
