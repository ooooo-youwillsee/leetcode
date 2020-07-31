package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/7/31 14:09
 */
public class Solution2 {
  
  
  // 跳跃查找
  public int findMagicIndex(int[] nums) {
    for (int i = 0; i < nums.length; ) {
      if (i == nums[i]) {
        return i;
      } else if (i < nums[i]) {
        i = nums[i];
      } else {
        i++;
      }
    }
    return -1;
  }
  
  private static void test(int[] nums) {
    Solution2 solution = new Solution2();
    int ans = solution.findMagicIndex(nums);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    test(new int[]{0, 2, 3, 4, 5});
    test(new int[]{1, 1, 1});
  }
}
