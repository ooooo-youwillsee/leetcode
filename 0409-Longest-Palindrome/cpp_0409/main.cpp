#include <iostream>
#include "Solution1.h"

void test(string s) {
  Solution solution;
  cout << solution.longestPalindrome(s) << endl;
}

int main() {

  test("");  // 0
  test("ccc");  // 3
  test("cccc"); // 4
  test("ccccb"); // 5
  test("abc"); // 1
  test("abbc"); // 3
  test("abccccdd");  // 7
  test("tattarrattat"); // 12
  test("ababababa");  // 9
  return 0;
}
