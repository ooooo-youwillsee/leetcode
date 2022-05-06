package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/5/20 17:15
 */
public class Solution2 {


  private void swap(char[] bits, int i, int j) {
    char tmp = bits[i];
    bits[i] = bits[j];
    bits[j] = tmp;
  }

  private void moveZero2LeftOrRight(char[] bits, int i, boolean right) {
    int k = i + 1, j = i + 1;
    char ch = right ? '1' : '0';
    while (j < bits.length) {
      if (bits[j] == ch) {
        swap(bits, k, j);
        k++;
      }
      j++;
    }
  }

  private char[] toCharArray(int num) {
    char[] bits = new char[32];
    for (int i = 31; i >= 0; i--) {
      if ((num & 1) == 1) bits[i] = '1';
      else bits[i] = '0';
      num >>= 1;
    }
    return bits;
  }

  public int[] findClosedNumbers(int num) {
    char[] bits = toCharArray(num);
    int big = -1, small = -1;
    for (int i = bits.length - 1; i > 0; i--) {
      if (bits[i - 1] == '0' && bits[i] == '1') {
        swap(bits, i - 1, i);
        moveZero2LeftOrRight(bits, i, false);
        big = Integer.parseInt(new String(bits), 2);
        break;
      }
    }
    bits = toCharArray(num);
    for (int i = bits.length - 1; i > 0; i--) {
      if (bits[i - 1] == '1' && bits[i] == '0') {
        swap(bits, i - 1, i);
        moveZero2LeftOrRight(bits, i, true);
        small = Integer.parseInt(new String(bits), 2);
        break;
      }
    }
    return new int[]{big, small};
  }


  private static void test(int num) {
    Solution2 solution = new Solution2();
    int[] ans = solution.findClosedNumbers(num);
    System.out.println(String.format("[%d, %d]", ans[0], ans[1]));
  }

  public static void main(String[] args) {
    test(2);  // [4, 1]
    test(1837591841); // [1837591842, 1837591832]
    test(1);  // [2, -1]
  }
}
