package com.ooooo;

/**
 * 求x和y的最大公约数，能不能被z整除？
 *
 * @author leizhijie
 * @since 2020/6/14 22:41
 */
public class Solution2 {
  
  
  public boolean canMeasureWater(int x, int y, int z) {
    if (x + y < z) return false; // 两个罐子不够
    if (x == z || y == z || x + y == z) return true;
    int min = x, max = y;
    if (x > y) {
      min = y;
      max = x;
    }
    if (min == 0) return max == z;
    while (max % min != 0) {
      int tmp = max % min;
      max = min;
      min = tmp;
    }
    return z % min == 0;
  }
  
  private static void test(int x, int y, int z) {
    Solution2 solution = new Solution2();
    boolean can = solution.canMeasureWater(x, y, z);
    System.out.println(can);
  }
  
  public static void main(String[] args) {
    test(3, 5, 4); // true
    test(2, 6, 5); // true
  }
}
