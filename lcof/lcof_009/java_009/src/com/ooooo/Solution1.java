package com.ooooo;

import java.util.Stack;

public class Solution1 {

  static class CQueue {

    private Stack<Integer> s1 = new Stack<>(), s2 = new Stack<>();

    public CQueue() {

    }

    public void appendTail(int value) {
      s1.push(value);
    }

    public int deleteHead() {
      if (s2.isEmpty()) {
        while(!s1.isEmpty()) {
          s2.add(s1.pop());
        }
      }
      return s2.isEmpty() ? -1 : s2.pop();
    }
  }


  public static void main(String[] args) {
    CQueue q = new CQueue();
    System.out.println(q.deleteHead()); // 3
    q.appendTail(5);
    q.appendTail(2);
    System.out.println(q.deleteHead()); // 5
    System.out.println(q.deleteHead()); // 2
  }

}