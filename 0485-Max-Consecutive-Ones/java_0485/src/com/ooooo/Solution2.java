package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/8/10 13:26
 */
public class Solution2 {
  
  
  public int findMaxConsecutiveOnes(int[] nums) {
    int count = 0, ans = 0;
    for (int num : nums) {
      if (num == 1) {
        count++;
      } else {
        ans = Math.max(ans, count);
        count = 0;
      }
    }
    return Math.max(ans, count);
  }
  
  private static void test(int[] nums) {
    Solution2 solution = new Solution2();
    int i = solution.findMaxConsecutiveOnes(nums);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 0, 1, 1, 0, 1}); // 2
    test(new int[]{1, 1, 0, 1, 1, 1}); // 3
    test(new int[]{0, 1, 1, 1, 1, 1}); // 5
    test(new int[]{0, 0, 0}); // 0
    test(new int[]{0, 0, 1}); // 1
    test(new int[]{0, 1, 1}); // 2
    test(new int[]{1}); // 1
    test(new int[]{0}); // 0
    test(new int[]{}); // 0
  }
}
