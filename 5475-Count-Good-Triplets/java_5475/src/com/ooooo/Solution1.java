package com.ooooo;

class Solution1 {
  
  public int countGoodTriplets(int[] arr, int a, int b, int c) {
    int count = 0;
    for (int i = 0; i < arr.length - 2; i++) {
      for (int j = i + 1; j < arr.length - 1; j++) {
        // 先判断一个
        if (Math.abs(arr[i] - arr[j]) > a) continue;
        for (int k = j + 1; k < arr.length; k++) {
          if (Math.abs(arr[j] - arr[k]) <= b && Math.abs(arr[i] - arr[k]) <= c) {
            count++;
          }
        }
      }
    }
    return count;
  }
  
  private static void test(int[] arr, int a, int b, int c) {
    Solution1 solution = new Solution1();
    int i = solution.countGoodTriplets(arr, a, b, c);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{
        3, 0, 1, 1, 9, 7
    }, 7, 2, 3); // 4
    
    test(new int[]{
        1, 1, 2, 2, 3
    }, 0, 0, 1); // 0
  }
}