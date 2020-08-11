package com.ooooo;

class Solution1 {
  
  public int[] constructRectangle(int area) {
    int L = (int) Math.sqrt(area);
    if (L * L == area) return new int[]{L, L};
    for (int i = L + 1; i <= area; i++) {
      if (area % i == 0) return new int[]{i, area / i};
    }
    return new int[0];
  }
  
  private static void test(int area) {
    Solution1 solution = new Solution1();
    int[] h_w = solution.constructRectangle(area);
    System.out.println(String.format("[L:%d, w:%d]", h_w[0], h_w[1]));
  }
  
  public static void main(String[] args) {
    test(8);
    test(4);
  }
}