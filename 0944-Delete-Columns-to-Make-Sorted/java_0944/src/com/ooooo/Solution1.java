package com.ooooo;

class Solution1 {
  
  public int minDeletionSize(String[] A) {
    int count = 0, cols = A[0].length();
    for (int j = 0; j < cols; j++) {
      for (int i = 0; i < A.length - 1; i++) {
        if (A[i].charAt(j) > A[i + 1].charAt(j)) {
          count++;
          break;
        }
      }
    }
    return count;
  }
  
  
  private static void test(String[] A) {
    Solution1 solution = new Solution1();
    int i = solution.minDeletionSize(A);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new String[]{
        "cba", "daf", "ghi"
    }); // 1
  }
}