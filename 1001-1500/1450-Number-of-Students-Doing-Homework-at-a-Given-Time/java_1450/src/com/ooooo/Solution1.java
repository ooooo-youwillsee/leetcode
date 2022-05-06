package com.ooooo;

class Solution1 {
  
  public int busyStudent(int[] startTime, int[] endTime, int queryTime) {
    int count = 0;
    for (int i = 0; i < startTime.length; i++) {
      if (queryTime >= startTime[i] && queryTime <= endTime[i]) count++;
    }
    return count;
  }
  
  private static void test(int[] startTime, int[] endTime, int queryTime) {
    Solution1 solution = new Solution1();
    int i = solution.busyStudent(startTime, endTime, queryTime);
    System.out.println(i);
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 2, 3}, new int[]{3, 2, 7}, 4); // 1
  }
}