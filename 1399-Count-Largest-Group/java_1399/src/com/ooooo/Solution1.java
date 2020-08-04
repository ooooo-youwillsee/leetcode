package com.ooooo;

import java.util.HashMap;
import java.util.Map;

class Solution1 {
  
  private int sumDigits(int n) {
    int sum = 0;
    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }
  
  public int countLargestGroup(int n) {
    Map<Integer, Integer> map = new HashMap<>(n + 1);
    int group_count = 0, group_size = 0;
    for (int i = 1; i <= n; i++) {
      int j = sumDigits(i);
      map.put(j, map.getOrDefault(j, 0) + 1);
      if (map.get(j) > group_size) {
        group_size = map.get(j);
        group_count = 0;
      }
      if (map.get(j) == group_size) {
        group_count++;
      }
    }
    return group_count;
  }
  
  private static void test(int n) {
    Solution1 solution = new Solution1();
    int i = solution.countLargestGroup(n);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(13); // 4
    test(15); // 6
    test(24); // 5
  }
}