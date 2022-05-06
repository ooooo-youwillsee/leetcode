package com.ooooo;

class Solution1 {
  
  public int minArray(int[] numbers) {
    int l = 0, r = numbers.length - 1;
    int min_v = numbers[0];
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (numbers[l] < numbers[mid]) {
        min_v = Math.min(min_v, numbers[l]);
        l = mid + 1;
      } else if (numbers[mid] < numbers[r]) {
        min_v = Math.min(min_v, numbers[mid]);
        r = mid - 1;
      } else {
        for (int i = l; i <= r; i++) {
          min_v = Math.min(min_v, numbers[i]);
        }
        break;
      }
    }
    return min_v;
  }
  
  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
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
        1,1,1
    });
  }
}