package com.ooooo;

/**
 * 桶排序
 * @author leizhijie
 * @since 2020/7/24 17:30
 */
public class Solution2 {
  
  public int arrayPairSum(int[] nums) {
    int[] arr = new int[20001];
    int sum = 0, d = 10000;
    for (int num : nums) {
      arr[num + d]++;
    }
    for (int i = 0; i < arr.length; i++) {
      sum += (arr[i] / 2) * (i - d);
      int j = i;
      if (arr[i] % 2 == 1) {
        while (true) {
          if (arr[i + 1] > 0) {
            arr[i + 1]--;
            sum += Math.min(j - d, i + 1 - d);
            break;
          }
          i++;
        }
      }
    }
    return sum;
  }
  
  private static void test(int[] nums) {
    Solution2 solution = new Solution2();
    int i = solution.arrayPairSum(nums);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{
        1, 4, 3, 2
    }); // 4
    
    test(new int[]{
        7, 3, 1, 0, 0, 6
    }); // 7
  }
  
  
}
