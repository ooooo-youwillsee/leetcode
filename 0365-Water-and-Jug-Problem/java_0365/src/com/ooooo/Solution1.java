package com.ooooo;

import java.util.HashSet;
import java.util.Set;
import java.util.Stack;
import javafx.util.Pair;

/**
 * dfs， 把下一次可能的选择添加栈中
 */
class Solution1 {
  
  public boolean canMeasureWater(int x, int y, int z) {
    Stack<Pair<Integer, Integer>> stack = new Stack<>(); // 可供选择的(x,y)
    Set<Pair<Integer, Integer>> marked = new HashSet<>(); // 标记有没有访问过
    stack.add(new Pair<>(0, 0)); // 开始时，水壶都是空，为0
    while (!stack.empty()) {
      Pair<Integer, Integer> pair = stack.pop();
      if (marked.contains(pair)) continue;
      marked.add(pair);
      int a = pair.getKey(), b = pair.getValue();
      if (a == z || b == z || a + b == z) return true;
      stack.add(new Pair<>(x, b)); // x 装满
      stack.add(new Pair<>(0, b)); // x 倒空
      stack.add(new Pair<>(a, y)); // y 装满
      stack.add(new Pair<>(a, 0)); // y 倒空
      stack.add(new Pair<>(a - Math.min(a, y - b), b + Math.min(a, y - b)));  // x 倒向 y
      stack.add(new Pair<>(a + Math.min(x - a, b), b - Math.min(x - a, b)));  // y 倒向 x
    }
    return false;
  }
  
  private static void test(int x, int y, int z) {
    Solution1 solution = new Solution1();
    boolean can = solution.canMeasureWater(x, y, z);
    System.out.println(can);
  }
  
  public static void main(String[] args) {
    test(3, 5, 4); // true
    test(2, 6, 5); // true
  }
}