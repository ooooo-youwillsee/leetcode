package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/8/1 21:34
 */
public class Solution2 {
  
  public int[] sortArrayByParityII(int[] A) {
    for (int i = 1, even = 0; i < A.length; i += 2) {
      // 如果奇数的位置是偶数，
      if (A[i] % 2 == 0) {
        while (A[even] % 2 == 0) {
          even += 2;
        }
        int temp = A[even];
        A[even] = A[i];
        A[i] = temp;
      }
    }
    return A;
  }
  
  private static void test(int[] A) {
    Solution2 solution = new Solution2();
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
