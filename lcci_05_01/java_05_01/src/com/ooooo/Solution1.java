package com.ooooo;

class Solution1 {

  public int insertBits(int N, int M, int i, int j) {
    N &= ~(((1 << (j - i + 1)) - 1) << i);
    return N | (M << i);
  }
}