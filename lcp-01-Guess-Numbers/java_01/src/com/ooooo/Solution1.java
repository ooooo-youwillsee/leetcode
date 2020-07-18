package com.ooooo;

class Solution1 {
  
  public int game(int[] guess, int[] answer) {
    int count = 0;
    for (int i = 0; i < guess.length; i++) {
      if (guess[i] == answer[i]) count++;
    }
    return count;
  }
  
  private static void test(int[] guess, int[] answer) {
    Solution1 solution = new Solution1();
    int i = solution.game(guess, answer);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{2, 2, 3}, new int[]{3, 2, 1}); // 1
  }
}