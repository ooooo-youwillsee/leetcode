package com.ooooo;

import java.util.Arrays;

/**
 * @author leizhijie
 * @since 2020/8/23 10:37
 */
public class Solution1 {
  
  public int maxCoins(int[] piles) {
    Arrays.sort(piles);
    int l = 0, r = piles.length - 1;
    int ans = 0;
    while (l < r) {
      l++;
      r -= 2;
      ans += piles[r + 1];
    }
    return ans;
  }
  
  private static void test(int[] piles) {
    Solution1 solution  = new Solution1();
    int i = solution.maxCoins(piles);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[] {
        9,8,7,6,5,1,2,3,4
    }); // 18
  }
}
