
package com.ooooo;

class Solution1 {
  
  public String longestCommonPrefix(String[] strs) {
    if (strs == null || strs.length == 0) return "";
    int min_len = Integer.MAX_VALUE;
    for (String str : strs) {
      min_len = Math.min(str.length(), min_len);
    }
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < min_len; i++) {
      char c = strs[0].charAt(i);
      for (int j = 1; j < strs.length; j++) {
        if (c != strs[j].charAt(i)) {
          return sb.toString();
        }
      }
      sb.append(c);
    }
    return sb.toString();
  }
  
  private static void test(String[] strs) {
    Solution1 solution = new Solution1();
    String prefix = solution.longestCommonPrefix(strs);
    System.out.println(prefix);
  }
  
  public static void main(String[] args) {
    test(new String[]{"flower", "flow", "flight", ""});
    test(new String[]{"flower", "flow", "flight"});
  }
}