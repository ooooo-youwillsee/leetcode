package com.ooooo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

/**
 * dp
 * <p>
 * dp[i][j]  表示 以 i，j 为后缀的最长重复子数组长度
 *
 * @author leizhijie
 * @since 2020/7/4 21:18
 */
public class Solution2 {

  public int findLength(int[] A, int[] B) {
    int len = 0;
    int[][] dp = new int[A.length + 1][B.length + 1];
    for (int i = 0; i < A.length; i++) {
      for (int j = 0; j < B.length; j++) {
        if (A[i] == B[j]) {
          dp[i + 1][j + 1] = dp[i][j] + 1;
        }
        len = Math.max(len, dp[i + 1][j + 1]);
      }
    }
    return len;
  }

  private static void test(int[] A, int[] B) {
    Solution2 solution = new Solution2();
    int n = solution.findLength(A, B);
    System.out.println(n);
  }

  public static void main(String[] args) {
    test(new int[]{1, 2, 3, 2, 1}, new int[]{3, 2, 1, 4, 7}); // 3

  }
}
