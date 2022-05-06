package com.ooooo;

import java.util.Stack;

/**
 * @author leizhijie
 * @since 2020/5/7 08:34
 *
 * min_s 只保留最小值
 */
public class Solution1 {

  static class SortedStack {

    Stack<Integer> s, min_s;

    public SortedStack() {
      s = new Stack<>();
      min_s = new Stack<>();
    }

    public void push(int val) {
      s.push(val);
      if (min_s.isEmpty()) {
        min_s.push(val);
        return;
      }
      if (min_s.peek() <= val) return;
      min_s.pop();
      min_s.push(val);
    }

    public void pop() {
      if (s.empty()) return;
      int min_v = min_s.pop(), next_min = Integer.MAX_VALUE;
      if (s.size() == 1) {
        s.pop();
        return;
      }
      boolean find_min = false;
      while (!s.isEmpty()) {
        int v = s.pop();
        if (find_min || v != min_v) {
          next_min = Math.min(next_min, v);
          min_s.push(v);
        } else if (v == min_v) {
          find_min = true;
        }
      }
      s.push(next_min);
      Stack<Integer> tmp = s;
      s = min_s;
      min_s = tmp;
    }

    public int peek() {
      return min_s.isEmpty() ? -1 : min_s.peek();
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
