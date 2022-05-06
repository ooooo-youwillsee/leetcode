package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/8/15 10:59
 */
public class Solution2 {
  
  
  int[][][] dp = new int[100][100][100];
  int[] boxes;
  
  private int dfs(int l, int r, int k) {
    if (l > r) return 0;
    if (dp[l][r][k] != 0) return dp[l][r][k];
    while (r > 1 && boxes[r] == boxes[r - 1]) {
      k++;
      r--;
    }
    dp[l][r][k] = dfs(l, r - 1, 0) + (k + 1) * (k + 1);
    
    for (int i = l; i < r; i++) {
      if (boxes[i] == boxes[r]) {
        dp[l][r][k] = Math.max(dp[l][r][k], dfs(l, i, k + 1) + dfs(i + 1, r - 1, 0));
      }
    }
    return dp[l][r][k];
  }
  
  public int removeBoxes(int[] boxes) {
    this.boxes = boxes;
    return dfs(0, boxes.length - 1, 0);
  }
  
  private static void test(int[] boxes) {
    Solution2 solution = new Solution2();
    int i = solution.removeBoxes(boxes);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 3, 2, 2, 2, 3, 4, 3, 1}); // 23
  }
  
}
