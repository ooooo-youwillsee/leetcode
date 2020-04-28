package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/4/28 17:18
 */
public class Solution2 {


  public boolean CheckPermutation(String s1, String s2) {
    if (s1.length() != s2.length()) {
      return false;
    }
    int ans = 0, s1_sum = 0, s2_sum = 0;
    for (int i = 0; i < s1.length(); i++) {
      ans = ans ^ s1.charAt(i) ^ s2.charAt(i);
      s1_sum += s1.charAt(i);
      s2_sum += s2.charAt(i);
    }
    return ans == 0 && s1_sum == s2_sum;
  }

  private static void test(String s1, String s2) {
    Solution1 solution = new Solution1();
    System.out.println(solution.CheckPermutation(s1, s2));
  }

  public static void main(String[] args) {
    test("abc", "bca");
    test("abc", "bad");
    test("aa", "bb");
  }
}
