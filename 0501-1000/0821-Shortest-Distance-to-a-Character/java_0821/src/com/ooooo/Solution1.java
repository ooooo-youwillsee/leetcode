package com.ooooo;

class Solution1 {
  
  public int[] shortestToChar(String S, char C) {
    int prevI = Integer.MAX_VALUE, curI = -1;
    int[] ans = new int[S.length()];
    for (int i = 0; i < S.length(); i++) {
      if (curI == -1) {
        for (int j = i; j < S.length(); j++) {
          if (S.charAt(j) == C) {
            curI = j;
            break;
          }
        }
      }
      ans[i] = Math.min(Math.abs(curI - i), Math.abs(i - prevI));
      if (ans[i] == 0) {
        prevI = curI;
        curI = -1;
      }
    }
    return ans;
  }
  
  private static void test(String s, char c) {
    Solution1 solution = new Solution1();
    int[] ints = solution.shortestToChar(s, c);
    for (int anInt : ints) {
      System.out.print(anInt + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test("loveleetcode", 'e'); // 3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0
    test("loveleetcode", 'o'); // 3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0
  }
}