package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/7/22 18:09
 */
public class Solution2 {
  
  public int minArray(int[] numbers) {
    for (int i = 0; i < numbers.length - 1; i++) {
      if (numbers[i] > numbers[i + 1]) return numbers[i + 1];
    }
    return numbers[0];
  }
  
  
  private static void test(int[] nums) {
    Solution2 solution = new Solution2();
    int i = solution.minArray(nums);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{
        3, 4, 5, 1, 2
    }); // 1
    test(new int[]{
        2, 2, 2, 0, 1
    }); // 0
    test(new int[]{
        1, 1, 1
    });
  }
}
