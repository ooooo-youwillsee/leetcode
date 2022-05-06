package com.ooooo;

import java.util.Stack;

/**
 * @author leizhijie
 * @since 2020/6/20 14:22
 */
public class Solution3 {
  
  
  // 单调递减栈，元素为下标
  public int[] dailyTemperatures(int[] T) {
    int[] ans = new int[T.length];
    Stack<Integer> stack = new Stack<>();
    for (int i = 0; i < T.length; i++) {
      while (!stack.empty() && T[stack.peek()] < T[i]) {
        Integer j = stack.pop();
        ans[j] = i - j;
      }
      stack.push(i);
    }
    return ans;
  }
  
  private static void test(int[] T) {
    Solution3 solution = new Solution3();
    int[] ans = solution.dailyTemperatures(T);
    for (int i : ans) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
  
  
  public static void main(String[] args) {
    test(new int[]{73, 74, 75, 71, 69, 72, 76, 73});
  }
}
