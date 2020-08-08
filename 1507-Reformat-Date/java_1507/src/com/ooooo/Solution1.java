package com.ooooo;

class Solution1 {
  
  public String reformatDate(String date) {
    String[] days = new String[]{"1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th", "10th", "11th", "12th",
        "13th", "14th", "15th", "16th", "17th", "18th", "19th", "20th", "21st", "22nd", "23rd", "24th", "25th", "26th",
        "27th", "28th", "29th", "30th", "31st"};
    String[] mothes = new String[]{
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    String[] split = date.split(" ");
    int day_index = -1, month_index = -1;
    for (int i = 0; i < days.length; i++) {
      if (days[i].equals(split[0])) {
        day_index = i;
        break;
      }
    }
    for (int i = 0; i < mothes.length; i++) {
      if (mothes[i].equals(split[1])) {
        month_index = i;
        break;
      }
    }
    return String.format("%s-%02d-%02d", split[2], month_index + 1, day_index + 1);
  }
  
  private static void test(String date) {
    Solution1 solution = new Solution1();
    String s = solution.reformatDate(date);
    System.out.println(s);
  }
  
  
  public static void main(String[] args) {
    test("20th Oct 2052");
  }
}