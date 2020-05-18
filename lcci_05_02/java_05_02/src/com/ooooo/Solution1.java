package com.ooooo;

class Solution1 {
  public String printBin(double num) {
    StringBuilder ans = new StringBuilder("0.");
    int count = 30;
    while (num > 0 && count > 0) {
      num *= 2;
      if (num >= 1) {
        ans.append("1");
        num -= 1;
      } else ans.append("0");
      count--;
    }
    return num != 0 ? "ERROR" : ans.toString();
  }

  private static void test(double num) {
    Solution1 solution = new Solution1();
    String ans = solution.printBin(num);
    System.out.println(ans);
  }

  public static void main(String[] args) {
    test(0.625);
    test(0.1);
  }
}