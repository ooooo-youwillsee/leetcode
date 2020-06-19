package com.ooooo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution1 {
  
  private List<Integer> sum = new ArrayList<>();
  
  private int getInsertIndex(int[] arr, int v) {
    if (v <= arr[0]) return 0;
    if (v > arr[arr.length - 1]) return arr.length;
    int l = 0, r = arr.length - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (mid + 1 < arr.length && v > arr[mid] && v <= arr[mid + 1]) return mid + 1;
      if (v <= arr[mid]) r = mid;
      else l = mid;
    }
    return -1;
  }
  
  // 优化点，前缀和
  private int getSum(int[] arr, int j, int v) {
    if (sum.isEmpty()) {
      int n = 0;
      for (int value : arr) {
        n += value;
        sum.add(n);
      }
    }
    return (j > 0 ? sum.get(j - 1) : 0) + v * (arr.length - j);
  }
  
  public int findBestValue(int[] arr, int target) {
    Arrays.sort(arr);
    int len = arr.length;
    int diff = target, min_v = 0;
    for (int v = Math.min(arr[0], target / arr.length); v <= arr[len - 1]; v++) {
      int i = getInsertIndex(arr, v);
      int sum = getSum(arr, i, v);
      int num = Math.abs(sum - target);
      if (num == 0) return v;
      if (num < diff) {
        diff = num;
        min_v = v;
      }
    }
    return min_v;
  }
  
  private static void test(int[] nums, int target) {
    Solution1 solution = new Solution1();
    int ans = solution.findBestValue(nums, target);
    System.out.println(ans);
    
    //System.out.println(solution.getInsertIndex(nums, 1));
    //System.out.println(solution.getInsertIndex(nums, 2));
    //System.out.println(solution.getInsertIndex(nums, 3));
    //System.out.println(solution.getInsertIndex(nums, 4));
    //System.out.println(solution.getInsertIndex(nums, 5));
  }
  
  public static void main(String[] args) {
    test(new int[]{2, 3, 5}, 10); // 5
    test(new int[]{4, 9, 3}, 10); // 3
    test(new int[]{60864, 25176, 27249, 21296, 20204}, 56803); // 11361
    
  }
}