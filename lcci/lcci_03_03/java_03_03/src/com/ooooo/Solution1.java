package com.ooooo;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * @author leizhijie
 * @since 2020/5/11 15:16
 *
 * 很重要的一点 -> cap = 0 边界条件
 */
public class Solution1 {

  static class StackOfPlates {

    private List<Stack<Integer>> data;
    private int cap;

    public StackOfPlates(int cap) {
      this.cap = cap;
      this.data = new ArrayList<>();
    }

    private Stack<Integer> getLastStack() {
      return data.get(data.size() - 1);
    }

    private void ensureCap() {
      if (cap != 0 && (data.isEmpty() || getLastStack().size() == cap))
        data.add(new Stack<>());
    }

    public void push(int val) {
      if (cap == 0) return;
      ensureCap();
      getLastStack().push(val);
    }

    public int pop() {
      return popAt(data.size() - 1);
    }

    public int popAt(int index) {
      if (cap == 0 || data.isEmpty() || index < 0 || index >= data.size()) return -1;
      Stack<Integer> s = data.get(index);
      int ret = s.pop();
      if (s.empty()) data.remove(index);
      return ret;
    }
  }

  public static void main(String[] args) {
    StackOfPlates stack = new StackOfPlates(2);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    System.out.println(stack.popAt(0)); // 2
    System.out.println(stack.popAt(0)); // 1
    System.out.println(stack.popAt(0)); // 3
  }
}
