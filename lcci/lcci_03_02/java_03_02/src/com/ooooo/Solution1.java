package com.ooooo;

import java.util.Stack;

/**
 * @author leizhijie
 * @since 2020/5/9 18:25
 */
public class Solution1 {

  static class MinStack {

    private Stack<Integer> s, min_s;

    public MinStack() {
      s = new Stack<>();
      min_s = new Stack<>();
    }

    public void push(int x) {
      s.push(x);
      if (min_s.empty() || min_s.peek() >= x) {
        min_s.push(x);
      }
    }

    public void pop() {
      int e = s.pop();
      if (e == min_s.peek()) min_s.pop();
    }

    public int top() {
      return s.peek();
    }

    public int getMin() {
      return min_s.peek();
    }
  }

  public static void main(String[] args) {
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    System.out.println(minStack.getMin());  // --> 返回 -3.
    minStack.pop();
    System.out.println(minStack.top());     // --> 返回 0.
    System.out.println(minStack.getMin());  //  --> 返回 -2.

  }
}
