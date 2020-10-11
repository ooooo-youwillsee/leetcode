package com.ooooo;

import java.util.ArrayList;
import java.util.List;

/**
 * 最优解， 中间是循环的，所以次数是一样的
 *
 * @author leizhijie
 * @since 2020/8/23 17:49
 */
public class Solution3 {
  
  private void add(List<Integer> ans, int l, int r) {
    while (l <= r) {
      ans.add(l++);
    }
  }
  
  public List<Integer> mostVisited(int n, int[] rounds) {
    int l = rounds[0], r = rounds[rounds.length - 1];
    List<Integer> ans = new ArrayList<>();
    if (l <= r) {
      add(ans, l, r);
    } else {
      add(ans, 1, r);
      add(ans, l, n);
    }
    return ans;
  }
  
  public static void test(int n, int[] rounds) {
    Solution2 solution = new Solution2();
    List<Integer> list = solution.mostVisited(n, rounds);
    for (Integer i : list) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(2, new int[]{2, 1, 2, 1, 2, 1, 2, 1, 2});
    test(4, new int[]{1, 3, 1, 2});
  }
}
