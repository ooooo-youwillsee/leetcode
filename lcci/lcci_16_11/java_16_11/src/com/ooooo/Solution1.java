package com.ooooo;

class Solution1 {

  public int[] divingBoard(int shorter, int longer, int k) {
    if (k == 0) return new int[0];
    if(shorter == longer) return new int[]{shorter * k};
    int[] ans = new int[k+1];
    for (int i = 0; i < k + 1; i++) {
      ans[i] = shorter * (k - i) + longer * i;
    }
    return ans;
  }

  private static void test(int s, int l, int k) {
    Solution1 solution = new Solution1();
    int[] nums = solution.divingBoard(s, l, k);
    for (int num : nums) {
      System.out.print(num + " ");
    }
    System.out.println();
  }

  public static void main(String[] args) {
    test(1, 2, 0);
    test(1, 2, 1);
    test(1, 2, 2);
    test(1, 2, 3);
  }
}