package com.ooooo;

class Solution1 {
  
  // 1,2,3,4,5,6,7,8,9,10 ==> 只有2，5能构成尾数为0，2肯定比5多，所以直接数5的个数就行了。
  public int trailingZeroes(int n) {
    int count = 0;
    while (n >= 5) {
      count += n / 5;
      n /= 5;
    }
    return count;
  }
  
  private static void test(int n) {
    Solution1 solution = new Solution1();
    int ans = solution.trailingZeroes(n);
    System.out.println(ans);
  }
  
  public static void main(String[] args) {
    test(3); // 0
    test(6); // 1
    test(11); // 1
    test(30); // 7
  }
}