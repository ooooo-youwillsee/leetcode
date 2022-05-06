package com.ooooo;

/**
 * dfs
 */
class Solution1 {
  
  private String s1;
  private String s2;
  private String s3;
  
  private boolean dfs(int i, int j, int k) {
    if (i == s1.length() && j == s2.length() && k == s3.length()) return true;
    if (i == s1.length()) return s2.substring(j).equals(s3.substring(k));
    if (j == s2.length()) return s1.substring(i).equals(s3.substring(k));
    char a = s1.charAt(i), b = s2.charAt(j), c = s3.charAt(k);
    boolean ans = false;
    if (a == c) ans = ans || dfs(i + 1, j, k + 1);
    if (b == c) ans = ans || dfs(i, j + 1, k + 1);
    return ans;
  }
  
  public boolean isInterleave(String s1, String s2, String s3) {
    if (s1.length() + s2.length() != s3.length()) return false;
    this.s1 = s1;
    this.s2 = s2;
    this.s3 = s3;
    return dfs(0, 0, 0);
  }
  
  private static void test(String s1, String s2, String s3) {
    Solution1 solution = new Solution1();
    boolean b = solution.isInterleave(s1, s2, s3);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test("aabcc", "dbbca", "aadbbcbcac"); // true
    test("aabcc", "dbbca", "aadbbbaccc"); // false
  }
}