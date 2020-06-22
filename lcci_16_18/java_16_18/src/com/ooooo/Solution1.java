package com.ooooo;


class Solution1 {
  
  public boolean patternMatching(String pattern, String value) {
    int count_a = 0, count_b = 0;
    for (char ch: pattern.toCharArray()) {
      if (ch == 'a') {
        ++count_a;
      } else {
        ++count_b;
      }
    }
    if (count_a < count_b) {
      int temp = count_a;
      count_a = count_b;
      count_b = temp;
      char[] array = pattern.toCharArray();
      for (int i = 0; i < array.length; i++) {
        array[i] = array[i] == 'a' ? 'b' : 'a';
      }
      pattern = new String(array);
    }
    if (value.length() == 0) {
      return count_b == 0;
    }
    if (pattern.length() == 0) {
      return false;
    }
    for (int len_a = 0; count_a * len_a <= value.length(); ++len_a) {
      int rest = value.length() - count_a * len_a;
      if ((count_b == 0 && rest == 0) || (count_b != 0 && rest % count_b == 0)) {
        int len_b = (count_b == 0 ? 0 : rest / count_b);
        int pos = 0;
        boolean correct = true;
        String value_a = "", value_b = "";
        for (char ch: pattern.toCharArray()) {
          if (ch == 'a') {
            String sub = value.substring(pos, pos + len_a);
            if (value_a.length() == 0) {
              value_a = sub;
            } else if (!value_a.equals(sub)) {
              correct = false;
              break;
            }
            pos += len_a;
          } else {
            String sub = value.substring(pos, pos + len_b);
            if (value_b.length() == 0) {
              value_b = sub;
            } else if (!value_b.equals(sub)) {
              correct = false;
              break;
            }
            pos += len_b;
          }
        }
        if (correct && !value_a.equals(value_b)) {
          return true;
        }
      }
    }
    return false;
  }
  
  private static void test(String pattern, String value) {
    Solution1 solution = new Solution1();
    boolean b = solution.patternMatching(pattern, value);
    System.out.println(b);
  }
  
  public static void main(String[] args) {
    test("aaaaab","xahnxdxyaahnxdxyaahnxdxyaahnxdxyaauxuhuo"); // true
    test("bbbbbbbbabbbbbbbbbbbabbbbbbba", "zezezezezezezezezkxzezezezezezezezezezezezkxzezezezezezezezkx"); // true
    test("bbba", "xxxxxx"); // true
    test("ab", ""); // false
    test("aaaa", "dogcatcatdog"); // false
    test("a", ""); // true
    test("abba", "dogcatcatdog"); // true
    test("abba", "dogcatcatfish"); // false
    test("abba", "dogdogdogdog"); // true
  }
}