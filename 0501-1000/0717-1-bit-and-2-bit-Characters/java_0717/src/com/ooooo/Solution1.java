package com.ooooo;

class Solution1 {
  
  public boolean isOneBitCharacter(int[] bits) {
    for (int i = 0; i < bits.length; ) {
      if (bits[i] == 1) {
        i += 2;
        if (i == bits.length) return false;
      } else {
        i++;
      }
    }
    return true;
  }
  
  
  private static void test(int[] bits) {
    Solution1 solution = new Solution1();
    boolean b = solution.isOneBitCharacter(bits);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 0, 0}); // true
    test(new int[]{1, 1, 1, 0}); // false
  }
}