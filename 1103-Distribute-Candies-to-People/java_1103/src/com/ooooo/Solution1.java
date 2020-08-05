package com.ooooo;

class Solution1 {
  
  public int[] distributeCandies(int candies, int num_people) {
    int[] people = new int[num_people];
    for (int count = 1, k = 0; candies > 0; count++) {
      count = Math.min(candies, count);
      people[k] += count;
      candies -= count;
      k = (k + 1) % num_people;
    }
    return people;
  }
  
  private static void test(int candies, int num_people) {
    Solution1 solution = new Solution1();
    int[] ints = solution.distributeCandies(candies, num_people);
    for (int num : ints) {
      System.out.print(num + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(7, 4);
    test(10, 3);
    
  }
}