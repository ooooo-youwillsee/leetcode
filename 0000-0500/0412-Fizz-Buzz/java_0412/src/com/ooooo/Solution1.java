package com.ooooo;

import java.util.ArrayList;
import java.util.List;

class Solution1 {
  
  public List<String> fizzBuzz(int n) {
    List<String> ans = new ArrayList<>();
    for (int i = 1; i <= n; i++) {
      if (i % 3 == 0 && i % 5 == 0) {
        ans.add("FizzBuzz");
      } else if (i % 3 == 0) {
        ans.add("Fizz");
      } else if (i % 5 == 0) {
        ans.add("Buzz");
      } else {
        ans.add(String.valueOf(i));
      }
    }
    return ans;
  }
  
  private static void test(int n) {
    Solution1 solution = new Solution1();
    List<String> strings = solution.fizzBuzz(n);
    for (String s : strings) {
      System.out.print(s + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(15);
  }
}