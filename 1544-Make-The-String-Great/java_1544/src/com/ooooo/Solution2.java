package com.ooooo;

import java.util.Stack;

/**
 * stack
 * @author leizhijie
 * @since 2020/8/9 18:45
 */
public class Solution2 {
  
  public String makeGood(String s) {
    Stack<Character> stack = new Stack<>();
    for (int i = 0; i < s.length(); i++) {
      if (!stack.isEmpty() && Math.abs(stack.peek() - s.charAt(i)) == 32) {
        stack.pop();
      } else {
        stack.add(s.charAt(i));
      }
    }
    StringBuilder sb = new StringBuilder();
    while (!stack.empty()) {
      sb.append(stack.pop());
    }
    return sb.reverse().toString();
  }
  
  private static void test(String s) {
    Solution2 solution = new Solution2();
    String s1 = solution.makeGood(s);
    System.out.println(s1);
  }
  
  public static void main(String[] args) {
    test("qFxXfQo");
    test("abBAcC");
    test("leEeetcode");
    test("cM");
  }
}
