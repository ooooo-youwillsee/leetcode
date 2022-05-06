package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/6/13 16:42
 */
public class Solution2 {
  
  public int addDigits(int num) {
    if (num > 9) {
      num = num % 9;
      if (num == 0) return 9;
    }
    return num;
  }
  
  private static void test(int num) {
    Solution2 solution = new Solution2();
    int ans = solution.addDigits(num);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    test(119);
    test(38);
  }
}
