package com.ooooo;

import java.util.ArrayList;
import java.util.List;

class Solution1 {
  
  public List<Integer> selfDividingNumbers(int left, int right) {
    List<Integer> ans = new ArrayList<>(right - left + 1);
    for (int i = left; i <= right; i++) {
      int num = i;
      boolean isSelfDividing = true;
      while (num > 0) {
        int a = num % 10;
        if (a == 0 || i % a != 0) {
          isSelfDividing = false;
          break;
        }
        num /= 10;
      }
      if (isSelfDividing) ans.add(i);
    }
    return ans;
  }
  
  
  private static void test(int l, int r) {
    Solution1 solution = new Solution1();
    List<Integer> list = solution.selfDividingNumbers(l, r);
    for (Integer i : list) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(1, 22); // 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22
  }
}