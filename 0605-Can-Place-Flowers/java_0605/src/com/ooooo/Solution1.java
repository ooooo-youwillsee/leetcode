package com.ooooo;

class Solution1 {
  
  /**
   * 也可以在两边加上0
   *
   * @param flowerbed
   * @param n
   * @return
   */
  public boolean canPlaceFlowers(int[] flowerbed, int n) {
    int len = flowerbed.length;
    for (int i = 0; i < len; i++) {
      if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0)
          && (i == flowerbed.length - 1 || flowerbed[i + 1] == 0)) {
        flowerbed[i] = 1;
        n--;
      }
    }
    return n < 0;
  }
  
  private static void test(int[] flowerbed, int n) {
    Solution1 solution = new Solution1();
    boolean b = solution.canPlaceFlowers(flowerbed, n);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test(new int[]{0, 0, 0, 1}, 1); // true
    test(new int[]{0, 0, 1, 0, 0}, 1); // true
    test(new int[]{1, 0, 0, 0, 1}, 1); // true
    test(new int[]{1, 0, 0, 0, 1}, 2); // false
    test(new int[]{1, 0, 0, 0, 0, 1}, 2); // false
  }
}