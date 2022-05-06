package com.ooooo;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * 归并排序
 *
 * @author leizhijie
 * @since 2020/7/5 17:45
 */
public class Solution2 {

  private static class Ele {

    int group;
    int value;

    public Ele(int group, int value) {
      this.group = group;
      this.value = value;
    }
  }

  public int kthSmallest(int[][] matrix, int k) {
    int n = matrix.length, count = 0;
    int[] groups = new int[n];
    PriorityQueue<Ele> q = new PriorityQueue<>(n, Comparator.comparingInt(o -> o.value));
    for (int g = 0; g < groups.length; g++) {
      q.add(new Ele(g, matrix[g][groups[g]++]));
    }
    while (count < k) {
      Ele ele = q.poll();
      count++;
      if (count == k) return ele.value;
      int g = ele.group;
      if (groups[g] < n) {
        q.add(new Ele(g, matrix[g][groups[g]++]));
      }
    }
    return -1;
  }

  private static void test(int[][] matrix, int k) {
    Solution2 solution = new Solution2();
    int n = solution.kthSmallest(matrix, k);
    System.out.println(n);
  }

  public static void main(String[] args) {
    test(new int[][]{
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    }, 8);
  }
}
