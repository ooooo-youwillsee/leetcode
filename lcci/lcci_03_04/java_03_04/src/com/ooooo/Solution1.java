package com.ooooo;

import java.util.Stack;

/**
 * @author leizhijie
 * @since 2020/5/10 13:56
 */
public class Solution1 {

  static class MyQueue {

    private Stack<Integer> s1, s2;

    /**
     * Initialize your data structure here.
     */
    public MyQueue() {
      s1 = new Stack<>();
      s2 = new Stack<>();
    }

    /**
     * Push element x to the back of queue.
     */
    public void push(int x) {
      s1.push(x);
    }

    /**
     * Removes the element from in front of queue and returns that element.
     */
    public int pop() {
      peek();
      return s2.pop();
    }

    /**
     * Get the front element.
     */
    public int peek() {
      if (s2.empty()) {
        while (!s1.empty()) {
          s2.push(s1.pop());
        }
      }
      return s2.peek();
    }

    /**
     * Returns whether the queue is empty.
     */
    public boolean empty() {
      return s1.empty() && s2.empty();
    }
  }

  public static void main(String[] args) {
    MyQueue queue = new MyQueue();
    queue.push(1);
    queue.push(2);
    System.out.println(queue.peek());  // 返回 1
    System.out.println(queue.pop());   // 返回 1
    queue.push(2);
    System.out.println(queue.pop());   // 返回 1
    System.out.println(queue.empty()); // 返回 false

  }
}
