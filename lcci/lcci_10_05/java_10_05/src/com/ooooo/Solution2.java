package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/6/5 12:07
 */
public class Solution2 {
  
  private int findString(String[] words, int l, int r, String s) {
    if (l > r) return -1;
    int mid = l + (r - l) / 2;
    String searchWord = words[mid];
    // 如果是空字符串，不知道下一次搜索区间，所有只能两边都搜索。
    if ("".equals(searchWord)) {
      int res_l = findString(words, l, mid - 1, s);
      if (res_l != -1) return res_l;
      int res_r = findString(words, mid + 1, r, s);
      return res_r;
    } else if (searchWord.compareTo(s) == 0) return mid;
    return searchWord.compareTo(s) < 0 ? findString(words, mid + 1, r, s)
        : findString(words, l, mid - 1, s);
  }
  
  public int findString(String[] words, String s) {
    return findString(words, 0, words.length - 1, s);
  }
  
  
  private static void test(String[] words, String s) {
    Solution2 solution = new Solution2();
    int ans = solution.findString(words, s);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    test(new String[]{"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""}, "ta");
    test(new String[]{"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""}, "ball");
  }
}
