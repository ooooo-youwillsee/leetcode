package com.ooooo;

class Solution1 {
  
  public String licenseKeyFormatting(String S, int K) {
    if (S.length() == 0) return "";
    StringBuilder sb = new StringBuilder();
    int count = 0;
    for (int i = S.length() - 1; i >= 0; i--) {
      if (S.charAt(i) == '-') continue;
      sb.append(Character.toUpperCase(S.charAt(i)));
      count++;
      if (count == K) {
        sb.append("-");
        count = 0;
      }
    }
    if (sb.length() > 0 && sb.charAt(sb.length() - 1) == '-')
      sb.deleteCharAt(sb.length() - 1);
    return sb.reverse().toString();
  }
  
  
  private static void test(String s, int K) {
    Solution1 solution = new Solution1();
    String ans = solution.licenseKeyFormatting(s, K);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    test("5F3Z-2e-9-w", 4);
    test("2-5g-3-J", 2);
  }
}