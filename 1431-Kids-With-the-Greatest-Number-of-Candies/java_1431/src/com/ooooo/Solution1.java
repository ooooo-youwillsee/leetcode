package com.ooooo;

import java.util.ArrayList;
import java.util.List;

class Solution1 {

  public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
    int min = candies[0], max = candies[0];
    for (int candy : candies) {
      min = Math.min(min, candy);
      max = Math.max(max, candy);
    }

    List<Boolean> can = new ArrayList<>(candies.length);
    for (int candy : candies) {
      can.add(candy + extraCandies >= max);
    }
    return can;
  }

  private static void test(int[] candies, int extraCandies) {
    Solution1 solution = new Solution1();
    List<Boolean> ans = solution.kidsWithCandies(candies, extraCandies);
    for (Boolean b : ans) {
      System.out.print(b + " ");
    }
    System.out.println();
  }

  public static void main(String[] args) {
    test(new int[]{3, 7}, 5); // true,false
    test(new int[]{2, 3, 5, 1, 3}, 3); // true,true,true,false,true
    test(new int[]{4, 2, 1, 1, 2}, 1); // true,false,false,false,false
    test(new int[]{12, 1, 12}, 10); // true,false,true
  }
}