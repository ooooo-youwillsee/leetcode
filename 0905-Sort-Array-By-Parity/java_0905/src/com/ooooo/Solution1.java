package com.ooooo;

class Solution1 {
  
  public int[] sortArrayByParity(int[] A) {
    int[] ans = new int[A.length];
    int l = 0, r = A.length - 1;
    for (int value : A) {
      if (value % 2 == 0) {
        ans[l++] = value;
      } else {
        ans[r--] = value;
      }
    }
    return ans;
  }
  
  
  private static void test(int[] A) {
    Solution1 solution = new Solution1();
    int[] ints = solution.sortArrayByParity(A);
    for (int anInt : ints) {
      System.out.print(anInt + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[]{
        3, 1, 2, 4
    });
  }
}