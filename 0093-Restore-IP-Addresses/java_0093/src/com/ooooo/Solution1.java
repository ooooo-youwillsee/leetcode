package com.ooooo;

import java.util.ArrayList;
import java.util.List;

class Solution1 {
  
  private int diot_count = 4;
  private final StringBuilder sb = new StringBuilder();
  private final List<String> ans = new ArrayList<>();
  
  private boolean check(String s, int i, int len) {
    if (i + len > s.length()) return false;
    String ip_str = s.substring(i, i + len);
    int num = Integer.parseInt(ip_str);
    return num >= 0 && num <= 255 && String.valueOf(num).length() == ip_str.length();
  }
  
  private void dfs(String s, int i) {
    if (i == s.length() && diot_count == 0) {
      ans.add(sb.substring(0, sb.length() - 1));
      return;
    }
    if (i > s.length() || diot_count <= 0) return;
    for (int len = 1; len <= 3; len++) {
      if (check(s, i, len)) {
        sb.append(s, i, i + len).append(".");
        diot_count--;
        dfs(s, i + len);
        diot_count++;
        sb.delete(sb.length() - len - 1, sb.length());
      }
    }
  }
  
  public List<String> restoreIpAddresses(String s) {
    if (s == null || s.length() < 4 || s.length() > 12) return ans;
    dfs(s, 0);
    return ans;
  }
  
  private static void test(String s) {
    Solution1 solution = new Solution1();
    List<String> ip_strs = solution.restoreIpAddresses(s);
    System.out.println(String.join(" ", ip_strs));
  }
  
  public static void main(String[] args) {
    test("172162541"); // ["17.216.25.41","17.216.254.1","172.16.25.41","172.16.254.1","172.162.5.41","172.162.54.1"]
    test("010010");
    test("25525511135"); // ["255.255.11.135", "255.255.111.35"]
    test("0000");
  }
}