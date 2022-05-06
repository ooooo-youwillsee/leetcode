package com.ooooo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * 暴力破解 timeout
 */
class Solution1 {
  
  private boolean isPalindrome(String s) {
    for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
      if (s.charAt(i) != s.charAt(j)) return false;
    }
    return true;
  }
  
  public List<List<Integer>> palindromePairs(String[] words) {
    List<List<Integer>> ans = new ArrayList<>();
    for (int i = 0; i < words.length; i++) {
      for (int j = 0; j < words.length; j++) {
        if (i != j && isPalindrome(words[i] + words[j])) {
          ans.add(Arrays.asList(i, j));
        }
      }
    }
    return ans;
  }
  
  private static void test(String[] words) {
    Solution1 solution = new Solution1();
    List<List<Integer>> pairs = solution.palindromePairs(words);
    for (List<Integer> pair : pairs) {
      System.out.print(String.format("[%d, %d] ", pair.get(0), pair.get(1)));
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new String[]{
        "abcd", "dcba", "lls", "s", "sssll"
    }); // [0,1],[1,0],[3,2],[2,4]
  }
}