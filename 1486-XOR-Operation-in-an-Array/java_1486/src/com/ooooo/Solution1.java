package com.ooooo;

class Solution1 {
  
  public int xorOperation(int n, int start) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans ^= (start + 2 * i);
    }
    return ans;
  }
  
  private static void test(int n, int start) {
    Solution1 solution = new Solution1();
    int i = solution.xorOperation(n, start);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(5, 0); // 8
  }
}