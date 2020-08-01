package com.ooooo;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.stream.Collectors;

class Solution1 {
  
  
  public int[] smallestRange(List<List<Integer>> nums) {
    int l = 0, r = Integer.MAX_VALUE;
    int range = r - l, max = 0;
    int[] indexes = new int[nums.size()];
    PriorityQueue<Integer> p = new PriorityQueue<>(
        Comparator.comparing(o -> nums.get(o).get(indexes[o])));
    for (int i = 0; i < nums.size(); i++) {
      p.add(i);
      max = Math.max(nums.get(i).get(0), max);
    }
    
    while (!p.isEmpty()) {
      // 每次取当前这一列的最大值和最小值，这样就至少包含一个数字
      Integer group = p.poll();
      int min = nums.get(group).get(indexes[group]);
      int curRange = max - min;
      if (curRange < range) {
        range = curRange;
        l = min;
        r = max;
      }
      indexes[group]++;
      if (indexes[group] == nums.get(group).size()) break;
      p.add(group);
      max = Math.max(max, nums.get(group).get(indexes[group]));
    }
    return new int[]{l, r};
  }
  
  private static void test(int[][] nums) {
    List<List<Integer>> collect = Arrays.stream(nums)
        .map(arr -> Arrays.stream(arr).boxed().collect(Collectors.toList()))
        .collect(Collectors.toList());
    Solution1 solution = new Solution1();
    int[] ints = solution.smallestRange(collect);
    for (int anInt : ints) {
      System.out.print(anInt + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    });
  }
}