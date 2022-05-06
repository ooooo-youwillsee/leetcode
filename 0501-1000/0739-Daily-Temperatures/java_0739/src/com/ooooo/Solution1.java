package com.ooooo;

class Solution1 {
  
  public int[] dailyTemperatures(int[] T) {
    int[] ans = new int[T.length];
    for (int i = 0; i < T.length; i++) {
      for (int j = i + 1; j < T.length; j++) {
        if (T[j] > T[i]) {
          ans[i] = j - i;
          break;
        }
      }
    }
    return ans;
  }
  
  private static void test(int[] T) {
    Solution1 solution = new Solution1();
    int[] ans = solution.dailyTemperatures(T);
    for (int i : ans) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
  
  
  public static void main(String[] args) {
    test(new int[]{73, 74, 75, 71, 69, 72, 76, 73});
  }
}