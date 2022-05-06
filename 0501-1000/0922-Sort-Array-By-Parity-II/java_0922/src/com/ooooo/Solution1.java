package com.ooooo;

class Solution1 {
  
  public int[] sortArrayByParityII(int[] A) {
    int[] ans = new int[A.length];
    int even = 0, odd = 1;
    for (int i : A) {
      if (i % 2 == 0) {
        ans[even] = i;
        even += 2;
      } else {
        ans[odd] = i;
        odd += 2;
      }
    }
    return ans;
  }
  
  private static void test(int[] A) {
    Solution1 solution = new Solution1();
    int[] ints = solution.sortArrayByParityII(A);
    for (int i : ints) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[]{
        4, 2, 5, 7
    });
  }
}