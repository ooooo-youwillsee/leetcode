package com.ooooo;

import java.util.Arrays;

class Solution1 {
  
  public int findContentChildren(int[] g, int[] s) {
    Arrays.sort(g);
    Arrays.sort(s);
    int count = 0;
    for (int i = 0, j = 0; i < g.length; i++) {
      while (j < s.length && s[j] < g[i]) {
        j++;
      }
      if (j >= s.length) break;
      count++;
      j++;
    }
    return count;
  }
  
  
  private static void test(int[] g, int[] s) {
    Solution1 solution = new Solution1();
    int contentChildren = solution.findContentChildren(g, s);
    System.out.println(contentChildren);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 2, 3}, new int[]{1, 1}); // 1
    test(new int[]{1, 2}, new int[]{1, 2, 3}); // 2
    test(new int[]{1, 2, 3}, new int[]{3}); // 1
  }
}