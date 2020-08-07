package com.ooooo;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution1 {
  
  public List<String> stringMatching(String[] words) {
    Set<String> ans = new HashSet<>();
    for (int i = 0; i < words.length; i++) {
      for (int j = 0; j < words.length; j++) {
        if (i != j && words[j].contains(words[i])) {
          ans.add(words[i]);
        }
      }
    }
    return new ArrayList<>(ans);
  }
  
  private static void test(String[] words) {
    Solution1 solution = new Solution1();
    List<String> strings = solution.stringMatching(words);
    System.out.println(String.join(",", strings));
  }
  
  public static void main(String[] args) {
    test(new String[]{
        "mass", "as", "hero", "superhero"
    });
  }
}