#include <iostream>
#include "Solution1.h"

void test(string s) {
  Solution solution;
  cout << solution.detectCapitalUse(s) << endl;
}

int main() {
  test("USA"); // 1
  test("FlaG"); // 0
  test("Google"); // 1
  return 0;
}
