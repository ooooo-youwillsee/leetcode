package com.ooooo;

import java.util.HashMap;
import java.util.Map;

/**
 * recursive + memo
 */
class Solution1 {
  
  private Map<Integer, Integer> memo = new HashMap<>();
  
  public int numTrees(int n) {
    if (n == 0 || n == 1) return 1;
    if (memo.containsKey(n)) return memo.get(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += numTrees(i) * numTrees(n - 1 - i);
    }
    memo.put(n, sum);
    return sum;
  }
  
  private static void test(int n) {
    Solution1 solution = new Solution1();
    int i = solution.numTrees(n);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(3); // 5
  }
}