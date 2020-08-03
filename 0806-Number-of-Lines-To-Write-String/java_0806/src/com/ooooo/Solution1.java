package com.ooooo;

class Solution1 {
  
  public int[] numberOfLines(int[] widths, String S) {
    int count = 1, sum = 0;
    for (int i = 0; i < S.length(); i++) {
      int num = widths[S.charAt(i) - 'a'];
      sum += num;
      if (sum > 100) {
        count++;
        sum = num;
      }
    }
    return new int[]{count, sum};
  }
  
  private static void test(int[] widths, String s) {
    Solution1 solution = new Solution1();
    int[] ans = solution.numberOfLines(widths, s);
    System.out.println(String.format("[%d, %d]", ans[0], ans[1]));
  }
  
  public static void main(String[] args) {
    test(new int[]{
        10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10
    }, "abcdefghijklmnopqrstuvwxyz"); // 3, 60
    
    test(new int[]{
        4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10
    }, "bbbcccdddaaa"); // 2, 4
  }
}