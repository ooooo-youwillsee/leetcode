package com.ooooo;

class Solution1 {
  
  public boolean containsPattern(int[] arr, int m, int k) {
    if (arr.length < m * k) return false;
    if (k == 1) return true;
    
    StringBuilder sb = new StringBuilder();
    for (int i : arr) {
      sb.append(i);
    }
    
    for (int i = 0; i < sb.length() - m + 1; i++) {
      String p = sb.substring(i, i + m);
      int count = 1;
      for (int j = i + m; j < sb.length() - m + 1; j += m) {
        String str = sb.substring(j, j + m);
        if (p.equals(str)) {
          count++;
          if (count >= k) return true;
        } else {
          break;
        }
      }
    }
    return false;
  }
  
  
  private static void test(int[] arr, int m, int k) {
    Solution1 solution = new Solution1();
    boolean b = solution.containsPattern(arr, m, k);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 2, 4, 4, 4, 4}, 1, 3);
  }
}

