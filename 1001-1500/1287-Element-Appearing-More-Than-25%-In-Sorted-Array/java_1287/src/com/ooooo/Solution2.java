package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/8/6 19:53
 */
public class Solution2 {
  
  
  public int findSpecialInteger(int[] arr) {
    int cur = 0, count = 0;
    for (int value : arr) {
      if (cur == value) {
        count++;
        if (count * 4 > arr.length) return value;
      } else {
        cur = value;
        count = 1;
      }
    }
    return cur;
  }
  
  private static void test(int[] arr) {
    Solution2 solution = new Solution2();
    int i = solution.findSpecialInteger(arr);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{
        1, 2, 2, 6, 6, 6, 6, 7, 10
    }); // 6
  }
}
