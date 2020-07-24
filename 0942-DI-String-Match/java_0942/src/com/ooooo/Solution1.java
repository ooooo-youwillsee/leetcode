package com.ooooo;

class Solution1 {
  
  public int[] diStringMatch(String S) {
    int left = 0, right = S.length();
    int[] nums = new int[S.length() + 1];
    for (int i = 0, j = 0; i < S.length(); i++) {
      if (S.charAt(i) == 'I') {
        nums[j++] = left++;
      } else {
        nums[j++] = right--;
      }
    }
    nums[S.length()] = right;
    return nums;
  }
  
  private static void test(String s) {
    Solution1 solution = new Solution1();
    int[] ints = solution.diStringMatch(s);
    for (int anInt : ints) {
      System.out.print(anInt + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test("IDID");
  }
}