package com.ooooo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution1 {
  
  private final List<String> ans = new ArrayList<>();
  private static final Map<Character, String> letter_map = new HashMap<>();
  
  static {
    letter_map.put('2', "abc");
    letter_map.put('3', "def");
    letter_map.put('4', "ghi");
    letter_map.put('5', "jkl");
    letter_map.put('6', "mno");
    letter_map.put('7', "pqrs");
    letter_map.put('8', "tuv");
    letter_map.put('9', "wxyz");
  }
  
  private void dfs(String digits, int i, StringBuilder sb) {
    if (i == digits.length()) {
      ans.add(sb.toString());
      return;
    }
    String letter = letter_map.get(digits.charAt(i));
    for (int j = 0; j < letter.length(); j++) {
      sb.append(letter.charAt(j));
      dfs(digits, i + 1, sb);
      sb.deleteCharAt(sb.length() - 1);
    }
  }
  
  public List<String> letterCombinations(String digits) {
    if (digits.length() == 0) return ans;
    dfs(digits, 0, new StringBuilder());
    return ans;
  }
  
  
  private static void test(String digits) {
    Solution1 solution = new Solution1();
    List<String> list = solution.letterCombinations(digits);
    for (String s : list) {
      System.out.print(s + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test("23");
  }
}