#include <iostream>
#include "Solution1.h"

void test(string moves) {
  Solution solution;
  cout << solution.judgeCircle(moves) << endl;
}

int main() {
  test("UD");  // 1
  test("LL");  // 0
  return 0;
}
