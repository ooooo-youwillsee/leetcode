package com.ooooo;

class Solution1 {
  
  private boolean hasZero(int n) {
    while (n > 0) {
      if (n % 10 == 0) return true;
      n /= 10;
    }
    return false;
  }
  
  public int[] getNoZeroIntegers(int n) {
    for (int i = 1; i < n; i++) {
      int k1 = i, k2 = n - i;
      if (!hasZero(k1) && !hasZero(k2)) return new int[]{k1, k2};
    }
    return new int[0];
  }
  
  
  private static void test(int n) {
    Solution1 solution = new Solution1();
    int[] ints = solution.getNoZeroIntegers(n);
    for (int anInt : ints) {
      System.out.print(anInt + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(1010);
  }
}