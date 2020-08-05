package com.ooooo;

class Solution1 {
  
  public int isPrefixOfWord(String sentence, String searchWord) {
    String[] strs = sentence.split(" ");
    for (int i = 0; i < strs.length; i++) {
      String str = strs[i];
      if (str.length() < searchWord.length()) continue;
      if (str.indexOf(searchWord) == 0) return i + 1;
    }
    return -1;
  }
  
  private static void test(String sentence, String searchWord) {
    Solution1 solution = new Solution1();
    int i = solution.isPrefixOfWord(sentence, searchWord);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test("i love eating burger", "burg"); // 4
  }
}