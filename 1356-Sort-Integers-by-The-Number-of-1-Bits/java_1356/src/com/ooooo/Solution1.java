package com.ooooo;

import java.util.Arrays;

class Solution1 {
  
  public int[] sortByBits(int[] arr) {
    return Arrays.stream(arr).boxed().sorted((o1, o2) -> {
      int i = Integer.bitCount(o1), j = Integer.bitCount(o2);
      return i == j ? o1.compareTo(o2) : i - j;
    }).mapToInt(Integer::intValue).toArray();
  }
  
  
  private static void test(int[] arr) {
    Solution1 solution = new Solution1();
    int[] ints = solution.sortByBits(arr);
    for (int i : ints) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[]{
        0, 1, 2, 3, 4, 5, 6, 7, 8
    }); // 0,1,2,4,8,3,5,6,7
  }
}