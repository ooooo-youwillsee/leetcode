package com.ooooo;

import java.time.LocalDateTime;

class Solution1 {
  
  private final String[] days = new String[]{"Sunday", "Monday", "Tuesday",
      "Wednesday", "Thursday", "Friday", "Saturday"};
  
  public String dayOfTheWeek(int day, int month, int year) {
    return days[LocalDateTime.of(year, month, day, 0, 0).getDayOfWeek().getValue() % 7];
  }
  
  private static void test(int day, int month, int year) {
    Solution1 solution = new Solution1();
    String s = solution.dayOfTheWeek(day, month, year);
    System.out.println(s);
  }
  
  public static void main(String[] args) {
    test(31, 8, 2019); // Saturday
    test(18, 7, 1999); // Sunday
    test(15, 8, 1993); // Sunday
  }
}