#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(string s) {
  Solution solution;
  cout << solution.repeatedSubstringPattern(s) << endl;
}

int main() {
  test("abab"); // 1
  test("aba");  // 0
  test("abcabcabcabc");  // 1
  return 0;
}
