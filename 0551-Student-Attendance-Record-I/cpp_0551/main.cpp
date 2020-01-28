#include <iostream>
#include "Solution1.h"

void test(string s) {
  Solution solution;
  cout << solution.checkRecord(s) << endl;
}

int main() {
  test("PPALLP"); // 1
  test("PPALLL"); // 0
  test("AA"); // 0
  return 0;
}
