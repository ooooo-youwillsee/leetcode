package com.ooooo;

import java.util.HashMap;
import java.util.Map;

class Solution1 {
  
  private Map<Integer, Integer> memo = new HashMap<>();
  
  public int integerBreak(int n) {
    if (memo.containsKey(n)) return memo.get(n);
    int ans = 1;
    for (int i = 1; i <= n / 2; i++) {
      // n -1 不继续拆分
      ans = Math.max(ans, i * (n - i));
      // n-i 继续拆分
      ans = Math.max(ans, i * integerBreak(n - i));
    }
    memo.put(n, ans);
    return ans;
  }
  
  
  private static void test(int n) {
    Solution1 solution = new Solution1();
    int i = solution.integerBreak(n);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(2); // 1
    test(10); // 36
    test(8); // 18
  }
}