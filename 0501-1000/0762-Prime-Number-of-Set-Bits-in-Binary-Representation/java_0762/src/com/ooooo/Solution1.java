package com.ooooo;

class Solution1 {
  
  // java 内置方法 Integer.bitCount()
  private int countBits(int num) {
    int count = 0;
    while (num > 0) {
      count++;
      num = num & (num - 1);
    }
    return count;
  }
  
  private boolean isPrime(int num) {
    if (num == 2) return true;
    if (num == 1 || num % 2 == 0) return false;
    for (int i = 2; i * i <= num; i++) {
      if (num % i == 0) return false;
    }
    return true;
  }
  
  public int countPrimeSetBits(int L, int R) {
    int ans = 0;
    boolean[] primes = new boolean[33];
    for (int i = 1; i <= 32; i++) {
      primes[i] = isPrime(i);
    }
    
    for (int i = L; i <= R; i++) {
      ans += primes[Integer.bitCount(i)] ? 1 : 0;
    }
    return ans;
  }
  
  private static void test(int L, int R) {
    Solution1 solution = new Solution1();
    int i = solution.countPrimeSetBits(L, R);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(6, 10); // 4
    test(10, 15); // 5
  }
}