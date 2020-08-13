package com.ooooo;

class Solution1 {
  
  private int plus(int a, int b, int carry, int k, StringBuilder sb) {
    int mod = 0;
    if (k < sb.length()) {
      mod = (a * b + carry + sb.charAt(k) - '0') % 10;
      carry = (a * b + carry + sb.charAt(k) - '0') / 10;
      sb.setCharAt(k, (char) (mod + '0'));
    } else {
      mod = (a * b + carry) % 10;
      carry = (a * b + carry) / 10;
      sb.append(mod);
    }
    return carry;
  }
  
  
  public String multiply(String num1, String num2) {
    if ("0".equals(num1) || "0".equals(num2)) return "0";
    StringBuilder sb = new StringBuilder();
    for (int i = num1.length() - 1; i >= 0; i--) {
      int k = num1.length() - 1 - i;
      int a = num1.charAt(i) - '0';
      int carry = 0;
      for (int j = num2.length() - 1; j >= 0; j--) {
        int b = num2.charAt(j) - '0';
        carry = plus(a, b, carry, k, sb);
        k++;
      }
      if (carry != 0) {
        String carry_str = String.valueOf(carry);
        carry = 0;
        for (int j = 0; j < carry_str.length(); j++) {
          carry = plus(carry_str.charAt(j) - '0', 1, carry, k, sb);
          k++;
        }
        if (carry != 0) sb.append(carry);
      }
    }
    return sb.reverse().toString();
  }
  
  private static void test(String num1, String num2) {
    Solution1 solution = new Solution1();
    String multiply = solution.multiply(num1, num2);
    System.out.println(multiply);
  }
  
  public static void main(String[] args) {
    test("123", "456");
    System.out.println(123 * 456);
  }
}