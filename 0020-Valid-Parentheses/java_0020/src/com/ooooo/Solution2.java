package com.ooooo;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

/**
 * stack
 *
 * @author leizhijie
 * @since 2020/8/14 09:28
 */
public class Solution2 {
  
  public boolean isValid(String s) {
    Stack<Character> stack = new Stack<>();
    Map<Character, Character> map = new HashMap<>();
    map.put('}', '{');
    map.put(']', '[');
    map.put(')', '(');
    
    for (int i = 0; i < s.length(); i++) {
      char c = s.charAt(i);
      if (!map.containsKey(c)) {
        stack.add(c);
      } else {
        if (stack.empty() || !map.get(c).equals(stack.peek())) {
          return false;
        } else {
          stack.pop();
        }
      }
    }
    return stack.isEmpty();
  }
  
  
  private static void test(String s) {
    Solution2 solution = new Solution2();
    boolean valid = solution.isValid(s);
    System.out.println(valid);
  }
  
  public static void main(String[] args) {
    test("()[]{}"); // true
    test("([)]"); // false
  }
}
