package com.ooooo;

class Solution {
  
  private char getBit(int n, int k) {
    if (n == 1) return '0';
    char c;
    if (k > count[n - 1] + 1) {
      c = getBit(n - 1, count[n] - k + 1);
      c = c == '1' ? '0' : '1';
    } else if (k < count[n - 1] + 1) {
      c = getBit(n - 1, k);
    } else {
      c = '1';
    }
    return c;
  }
  
  private int[] count;
  
  public char findKthBit(int n, int k) {
    count = new int[n + 1];
    count[1] = 1;
    for (int i = 2; i <= n; i++) {
      count[i] = 2 * count[i - 1] + 1;
    }
    return getBit(n, k);
  }
}