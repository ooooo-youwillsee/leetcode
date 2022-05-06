package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/5/24 12:07
 */
public class Solution2 {

  public int multiply(int A, int B) {
    return B == 1 ? A : A + multiply(A, B - 1);
  }

  private static void test(int A, int B) {
    Solution2 solution = new Solution2();
    int ans = solution.multiply(A, B);
    System.out.println(ans);
  }

  public static void main(String[] args) {
    test(1, 2);
  }
}
