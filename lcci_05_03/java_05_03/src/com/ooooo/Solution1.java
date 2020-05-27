package com.ooooo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution1 {
  public int reverseBits(int num) {
    StringBuilder bits = new StringBuilder();
    //   bit_0 -> 0出现的位置
    List<Integer> bit_0 = new ArrayList<>();
    for (int i = 0; i < 32; i++) {
      int n = 1 << i;
      if ((num & n) != 0) bits.append(1);
      else {
        bits.append(0);
        bit_0.add(i);
      }
    }
    int ans = 0;
    for (Integer index_0 : bit_0) {
      bits.setCharAt(index_0,'1');
      int count = Arrays.stream(bits.toString().split("0"))
        .map(String::length).max(Integer::compareTo).orElse(0);
      ans = Math.max(ans, count);
      bits.setCharAt(index_0,'0');
    }
    return ans;
  }

  private static void test(int num) {
    Solution1 solution = new Solution1();
    int ans = solution.reverseBits(num);
    System.out.println(ans);
  }

  public static void main(String[] args) {
    test(2147482622); // 30
    test(1775); // 8
    test(7); // 4
  }
}