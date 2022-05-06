package com.ooooo;

class Solution1 {
  
  public double average(int[] salary) {
    double sum = 0, max = salary[0], min = salary[0];
    for (int i : salary) {
      sum += i;
      max = Math.max(max, i);
      min = Math.min(min, i);
    }
    return (sum - max -min) /(salary.length - 2);
  }
  
  private static void test(int[] salary) {
    Solution1 solution = new Solution1();
    double v = solution.average(salary);
    System.out.println(v);
  }
  
  public static void main(String[] args) {
    test(new int[]{4000, 3000, 1000, 2000}); // 2500.00000
  }
  
}