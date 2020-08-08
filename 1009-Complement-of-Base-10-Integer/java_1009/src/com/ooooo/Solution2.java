package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/8/8 19:03
 */
public class Solution2 {
  
  public int bitwiseComplement(int N) {
    if (N == 0) return 1;
    int num = N;
    int i = 0;
    while (N > 0) {
      i++;
      N >>= 1;
    }
    return num ^ ((1 << i) - 1);
  }
  
  
  private static void test(int N) {
    Solution2 solution = new Solution2();
    int i = solution.bitwiseComplement(N);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(0); // 1
    test(5); // 2
    test(7); // 0
    test(10); // 5
  }
}
