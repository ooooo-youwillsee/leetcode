package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/6/20 14:01
 */
public class Solution2 {
  
  
  public int[] dailyTemperatures(int[] T) {
    int[] ans = new int[T.length];
    for (int i = T.length - 2; i >= 0; i--) {
      for (int j = i + 1; j < T.length; j += ans[j]) {
        if (T[i] < T[j]) {
          ans[i] = j - i;
          break;
        } else if (ans[j] == 0) {
          // T[j] = 0 表示大于j的没有，也就是说大于i的没有
          ans[i] = 0;
          break;
        }
      }
    }
    return ans;
  }
  
  private static void test(int[] T) {
    Solution2 solution = new Solution2();
    int[] ans = solution.dailyTemperatures(T);
    for (int i : ans) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
  
  
  public static void main(String[] args) {
    test(new int[]{73, 74, 75, 71, 69, 72, 76, 73});
  }
}
