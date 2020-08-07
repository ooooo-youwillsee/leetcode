package com.ooooo;

class Solution1 {
  
  public int binaryGap(int N) {
    int dist = 0, prev = -1, cur = 1;
    while (N > 0) {
      if ((N & 1) > 0) {
        if (prev == -1) prev = cur;
        dist = Math.max(cur - prev, dist);
        prev = cur;
      }
      cur++;
      N >>= 1;
    }
    return dist;
  }
  
  private static void test(int N) {
    Solution1 solution = new Solution1();
    int dist = solution.binaryGap(N);
    System.out.println(dist);
  }
  
  public static void main(String[] args) {
    test(22); // 2
    test(6); // 1
  }
}