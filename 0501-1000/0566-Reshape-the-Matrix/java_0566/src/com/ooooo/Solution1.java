package com.ooooo;

class Solution1 {
  
  public int[][] matrixReshape(int[][] nums, int r, int c) {
    int m = nums.length, n = nums[0].length;
    if (m * n != r * c) return nums;
    int[][] newArr = new int[r][c];
    int newi = 0, newj = 0;
    for (int[] num : nums) {
      for (int j = 0; j < n; j++) {
        newArr[newi][newj++] = num[j];
        if (newj == c) {
          newi++;
          newj = 0;
        }
      }
    }
    return newArr;
  }
  
  private static void test(int[][] nums, int r, int c) {
    Solution1 solution = new Solution1();
    int[][] reshape = solution.matrixReshape(nums, r, c);
    for (int[] row : reshape) {
      for (int i : row) {
        System.out.print(i + " ");
      }
      System.out.println();
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {1, 2},
        {3, 4}
    }, 1, 4);
  }
}