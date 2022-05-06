package com.ooooo;

import java.util.Arrays;

class Solution1 {
  
  // 先全部去B， N个人去A
  public int twoCitySchedCost(int[][] costs) {
    int[] nums = new int[costs.length];
    int sum = 0;
    for (int i = 0; i < costs.length; i++) {
      nums[i] = costs[i][0] - costs[i][1];
      sum += costs[i][1];
    }
    Arrays.sort(nums);
    for (int i = 0; i < costs.length / 2; i++) {
      sum += nums[i];
    }
    return sum;
  }
  
  
  private static void test(int[][] costs) {
    Solution1 solution = new Solution1();
    int min_costs = solution.twoCitySchedCost(costs);
    System.out.println(min_costs);
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {10, 20}, {30, 200}, {400, 50}, {30, 20}
    }); // 110
    
    test(new int[][]{
        {259, 770}, {448, 54}, {926, 667}, {184, 139}, {840, 118}, {577, 469}
    }); // 1859
    
  }
}