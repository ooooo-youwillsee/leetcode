package com.ooooo;

import java.util.Arrays;

/**
 * @author leizhijie
 * @since 2020/7/22 18:26
 */
public class Solution2 {
  
  public boolean canBeEqual(int[] target, int[] arr) {
    Arrays.sort(target);
    Arrays.sort(arr);
    for (int i = 0; i < target.length; i++) {
      if (target[i] != arr[i]) return false;
    }
    return true;
  }
  
  private static void test(int[] target, int[] arr) {
    Solution2 solution = new Solution2();
    boolean b = solution.canBeEqual(target, arr);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 2, 3, 4}, new int[]{2, 4, 1, 3});
    test(new int[]{1, 2, 3, 4}, new int[]{2, 4, 1, 5});
  }
}
