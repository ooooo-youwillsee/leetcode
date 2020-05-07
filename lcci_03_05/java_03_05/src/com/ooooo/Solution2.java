package com.ooooo;

import java.util.Stack;

/**
 * @author leizhijie
 * @since 2020/5/7 09:15
 *
 * help 存放大于val的值
 */
public class Solution2 {


  static class SortedStack {

    Stack<Integer> s, help;

    public SortedStack() {
      s = new Stack<>();
      help = new Stack<>();
    }

    public void push(int val) {
      if (s.isEmpty() || val <= s.peek()) {
        s.push(val);
      } else {
        while (!s.isEmpty() && s.peek() <= val) help.push(s.pop());
        help.push(val);
        while (!help.isEmpty()) s.push(help.pop());
      }
    }

    public void pop() {
      if (!s.isEmpty()) s.pop();
    }

    public int peek() {
      return s.isEmpty() ? -1 : s.peek();
    }

    public boolean isEmpty() {
      return s.isEmpty();
    }
  }

  public static void main(String[] args) {
    SortedStack stack = new SortedStack();
    stack.push(1);
    stack.push(2);
    System.out.println(stack.peek());
    stack.pop();
    System.out.println(stack.peek());
    stack.pop();
    System.out.println(stack.isEmpty());

  }
}
