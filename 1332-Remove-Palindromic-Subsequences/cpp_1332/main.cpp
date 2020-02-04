#include <iostream>
#include "Solution1.h"

void test(string s) {
  Solution solution;
  cout << solution.removePalindromeSub(s) << endl;
}

int main() {
  test(""); // 0
  test("ababa"); // 1
  test("abb"); // 2
  test("baabb"); // 2
  test("ababb"); // 2
  test("abbaaaab"); // 2
  return 0;
}
