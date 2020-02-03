#include <iostream>
#include "Solution1.h"

void test(string s) {
  Solution solution;
  cout << solution.balancedStringSplit(s) << endl;
}

int main() {
  test("RLRRLLRLRL"); // 4
  test("RLLLLRRRLR"); // 3
  test("LLLLRRRR"); // 1
  return 0;
}
