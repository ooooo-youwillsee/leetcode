package com.ooooo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author leizhijie
 * @since 2020/6/19 22:06
 */
public class Solution2 {
  
  private List<Integer> sum = null;
  
  // 前缀和
  private void makePrefixSum(int[] arr) {
    sum = new ArrayList<>(arr.length + 1);
    sum.add(0);
    for (int i = 0; i < arr.length; i++) {
      sum.add(sum.get(i) + arr[i]);
    }
  }
  
  private int getSum(int[] arr, int v) {
    int i = Arrays.binarySearch(arr, v);
    if (i < 0) i = -(i + 1);
    return sum.get(i) + (arr.length - i) * v;
  }
  
  public int findBestValue(int[] arr, int target) {
    Arrays.sort(arr);
    makePrefixSum(arr);
    
    int l = 0, r = arr[arr.length - 1], ans = 0;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      int cur = getSum(arr, mid);
      if (cur <= target) {
        // 把最接近的值保存下来
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    int small = getSum(arr, ans);
    int big = getSum(arr, ans + 1);
    return Math.abs(small - target) <= Math.abs(big - target) ? ans : ans + 1;
  }
  
  private static void test(int[] nums, int target) {
    Solution2 solution = new Solution2();
    int ans = solution.findBestValue(nums, target);
    System.out.println(ans);
    //System.out.println(Arrays.binarySearch(nums, 4));
  }
  
  public static void main(String[] args) {
    test(new int[]{2, 3, 5}, 10); // 5
    test(new int[]{4, 9, 3}, 10); // 3
    test(new int[]{60864, 25176, 27249, 21296, 20204}, 56803); // 11361
    
  }
}
