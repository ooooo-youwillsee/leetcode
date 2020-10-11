package com.ooooo;

class Solution1 {
  
  public int findKthPositive(int[] arr, int k) {
    int i = 0, cur = 0;
    while (i < arr.length && k > 0) {
      cur++;
      if (arr[i] != cur) {
        k--;
      } else {
        i++;
      }
    }
    while (k > 0) {
      k--;
      cur++;
    }
    return cur;
  }
  
  private static void test(int[] arr, int k) {
    Solution1 solution = new Solution1();
    int kthPositive = solution.findKthPositive(arr, k);
    System.out.println(kthPositive);
  }
  
  public static void main(String[] args) {
    test(new int[]{2, 3, 4, 7, 11}, 5); // 9
    test(new int[]{1, 2, 3, 4}, 2); // 6
  }
}