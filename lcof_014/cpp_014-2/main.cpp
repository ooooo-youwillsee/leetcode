#include <iostream>
#include "Solution1.h"

void test(int n) {
  Solution solution;
  cout << solution.cuttingRope(n) << endl;
}

int main() {
  test(2);  // 1
  test(10);  // 36
  test(120);  // 36
  return 0;
}
