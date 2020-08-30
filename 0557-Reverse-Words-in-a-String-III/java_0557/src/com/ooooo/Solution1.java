package com.ooooo;

import java.util.Arrays;
import java.util.function.Function;
import java.util.stream.Collectors;

class Solution1 {
  
  public String reverseWords(String s) {
    Function<String, String> reverse_word = (str) -> new StringBuilder(str).reverse().toString();
    return Arrays.stream(s.split(" ")).map(reverse_word).collect(Collectors.joining(" "));
  }
  
  private static void test(String s) {
    Solution1 solution = new Solution1();
    String reverseWords = solution.reverseWords(s);
    System.out.println(reverseWords);
  }
  
  public static void main(String[] args) {
    test("Let's take LeetCode contest");
  }
}