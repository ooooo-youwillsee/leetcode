package com.ooooo;

/**
 * dfs timeout
 */
class Solution1 {
  
  private int max = 0;
  
  private void dfs(StringBuilder sb, int sum) {
    if (sb.length() == 0) {
      max = Math.max(max, sum);
      return;
    }
    for (int i = 0, k = 0; i < sb.length(); i++) {
      if (i == sb.length() - 1 || sb.charAt(i) != sb.charAt(i + 1)) {
        String tmp = sb.substring(k, i + 1);
        sb.delete(k, i + 1);
        dfs(sb, sum + (i + 1 - k) * (i + 1 - k));
        sb.insert(k, tmp);
        k = i + 1;
      }
    }
  }
  
  public int removeBoxes(int[] boxes) {
    StringBuilder sb = new StringBuilder();
    for (int box : boxes) {
      sb.append(box);
    }
    
    dfs(sb, 0);
    return max;
  }
  
  private static void test(int[] boxes) {
    com.ooooo.Solution1 solution = new com.ooooo.Solution1();
    int i = solution.removeBoxes(boxes);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 3, 2, 2, 2, 3, 4, 3, 1}); // 23
  }
}