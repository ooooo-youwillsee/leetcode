#include <iostream>
#include "Solution1.h"

void test(string s, string p) {
  Solution solution;
  cout << solution.isMatch(s, p) << endl;
}

int main() {
  test("ab",".*c"); // 0
  test("a","ab*"); // 1
  test("ab", ".*"); // 1
  test("aa", "a*"); // 1
  test("aaca","ab*a*c*a"); // 1
  test("aaa","ab*ac*a"); // 1
  test("", ""); // 1
  test("aa", "a"); // 0
  test("aab", "c*a*b"); // 1
  test("mississippi", "mis*is*p*."); // 0
  return 0;
}
