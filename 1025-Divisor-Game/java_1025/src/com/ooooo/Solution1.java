package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/7/24 14:31
 */
public class Solution1 {
  
  public boolean divisorGame(int N) {
    return N % 2 == 0;
  }
  
  private static void test(int N) {
    Solution1 solution = new Solution1();
    boolean b = solution.divisorGame(N);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test(5);
  }
}
