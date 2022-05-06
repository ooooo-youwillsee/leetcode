#include <iostream>
#include "Solution1.h"

void testSimplify(string s) {
  Solution solution;
  cout << solution.simplify(s) << endl;
}

void test(string a, string b) {
  Solution solution;
  cout << solution.buddyStrings(a, b) << endl;
}

int main() {
  test("ab", "ba"); // 1
  test("ab", "ab"); // 0
  test("aa", "aa"); // 1
  test("aaaaaaabc", "aaaaaaacb"); // 1
  test("", "aa"); // 0
  test("", ""); // 0
  test("abab", "abab"); // 1
  test("acccccb", "bccccca"); // 1
  test("accccbc", "bccccac"); // 1
  return 0;
}
