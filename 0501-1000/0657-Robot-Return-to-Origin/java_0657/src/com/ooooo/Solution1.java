package com.ooooo;

class Solution1 {
  
  public boolean judgeCircle(String moves) {
    int y = 0, x = 0;
    for (int i = 0; i < moves.length(); i++) {
      char c = moves.charAt(i);
      switch (c) {
        case 'U':
          y++;
          break;
        case 'D':
          y--;
          break;
        case 'L':
          x--;
          break;
        case 'R':
          x++;
          break;
      }
    }
    return x == 0 && y == 0;
  }
  
  
  private static void test(String moves) {
    Solution1 solution = new Solution1();
    boolean b = solution.judgeCircle(moves);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test("UD");
    test("LL");
  }
}