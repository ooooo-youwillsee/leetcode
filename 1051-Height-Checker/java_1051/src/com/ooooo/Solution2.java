package com.ooooo;

/**
 *
 * 桶排序
 * @author leizhijie
 * @since 2020/7/23 20:25
 */
public class Solution2 {
  
  public int heightChecker(int[] heights) {
    int[] arr = new int[101];
    for (int height : heights) {
      arr[height]++;
    }
    int count = 0, j = 1;
    for (int i = 0; i < heights.length; j++) {
      while (arr[j]-- > 0) {
        if (heights[i++] != j) {
          count++;
        }
      }
    }
    return count;
  }
  
  private static void test(int[] heights) {
    Solution2 solution = new Solution2();
    int i = solution.heightChecker(heights);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 1, 4, 2, 1, 3});
  }
}
