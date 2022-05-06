package com.ooooo;

class Solution1 {

  public int findString(String[] words, String s) {
    for (int i = 0; i < words.length; i++) {
      if (words[i].equals(s)) return i;
    }
    return -1;
  }


  private static void test(String[] words, String s) {
    Solution1 solution = new Solution1();
    int ans = solution.findString(words, s);
    System.out.println(ans);
  }

  public static void main(String[] args) {
    test(new String[]{
        "at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""
    }, "ta");
  }
}