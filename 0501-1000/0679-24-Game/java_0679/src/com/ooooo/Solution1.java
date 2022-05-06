package com.ooooo;


import java.util.ArrayList;
import java.util.List;

class Solution1 {
  
  private final int add = 1, multiply = 2, substract = 3, divide = 4;
  
  private boolean dfs(List<Double> list) {
    if (list.isEmpty()) return false;
    if (list.size() == 1) return Math.abs(list.get(0) - 24) <= Math.pow(10, -6);
    
    for (int i = 0; i < list.size(); i++) {
      for (int j = 0; j < list.size(); j++) {
        if (i != j) {
          // 选取剩余数字
          List<Double> others = new ArrayList<>();
          for (int k = 0; k < list.size(); k++) {
            if (k != i && k != j) {
              others.add(list.get(k));
            }
          }
          // 对两个数字分别做 + - * /, 优化点，+ 和 * 满足交换律
          for (int k = 1; k <= 4; k++) {
            if (k <= 2 && i > j) continue;
            if (k == add) others.add(list.get(i) + list.get(j));
            else if (k == multiply) others.add(list.get(i) * list.get(j));
            else if (k == substract) others.add(list.get(i) - list.get(j));
            else if (k == divide) others.add(list.get(i) / list.get(j));
            if (dfs(others)) return true;
            others.remove(others.size() - 1);
          }
        }
      }
    }
    return false;
  }
  
  public boolean judgePoint24(int[] nums) {
    List<Double> list = new ArrayList<>(4);
    for (int num : nums) {
      list.add((double) num);
    }
    return dfs(list);
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    boolean b = solution.judgePoint24(nums);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test(new int[]{4, 1, 8, 7}); // true
    test(new int[]{1, 2, 1, 2}); // false
  }
}