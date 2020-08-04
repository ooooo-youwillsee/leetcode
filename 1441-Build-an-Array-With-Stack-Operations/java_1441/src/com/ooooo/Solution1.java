package com.ooooo;

import java.util.ArrayList;
import java.util.List;

class Solution1 {
  
  private String PUSH = "Push", POP = "Pop";
  
  public List<String> buildArray(int[] target, int n) {
    List<String> ans = new ArrayList<>();
    int i = 1;
    for (int j = 0; j < target.length; i++) {
      ans.add(PUSH);
      if (target[j] == i) {
        j++;
      } else {
        ans.add(POP);
      }
    }
    return ans;
  }
  
  private static void test(int[] target, int n) {
    Solution1 solution = new Solution1();
    List<String> ans = solution.buildArray(target, n);
    for (String s : ans) {
      System.out.println(s);
    }
  }
  
  
  public static void main(String[] args) {
    test(new int[]{
        1, 3
    }, 3); // "Push","Push","Pop","Push"
  }
}