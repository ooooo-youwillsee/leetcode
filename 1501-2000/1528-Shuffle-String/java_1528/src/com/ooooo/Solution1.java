package com.ooooo;

class Solution1 {
  
  public String restoreString(String s, int[] indices) {
    StringBuilder sb = new StringBuilder(s);
    for (int i = 0; i < indices.length; i++) {
      sb.setCharAt(indices[i], s.charAt(i));
    }
    return sb.toString();
  }
  
  
  private static void test(String s, int[] indices) {
    Solution1 solution = new Solution1();
    String ans = solution.restoreString(s, indices);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    test("codeleet", new int[]{4, 5, 6, 7, 0, 2, 1, 3}); // leetcode
  }
  
}