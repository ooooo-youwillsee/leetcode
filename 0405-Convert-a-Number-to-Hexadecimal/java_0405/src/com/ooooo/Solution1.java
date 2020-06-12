package com.ooooo;

class Solution1 {
  
  public String toHex(long num) {
    if (num == 0) return "0";
    String hex = "0123456789abcdef";
    StringBuilder sb = new StringBuilder();
    while (num != 0 && sb.length() < 8) {
      sb.append(hex.charAt((int) (num & 0xf)));
      num >>= 4;
    }
    return sb.reverse().toString();
  }
  
  private static void test(int num) {
    Solution1 solution = new Solution1();
    String s = solution.toHex(num);
    System.out.println(s);
  }
  
  public static void main(String[] args) {
    // -1 的补码，是正数1，取反加1
    test(-1);
    test(26);
    test(32);
  }
}