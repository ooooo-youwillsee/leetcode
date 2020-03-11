#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(int n) {
  Solution solution;
  cout << solution.cuttingRope(n) << endl;
}

int main() {
  test(4); // 4
  test(3); // 2
  test(2); // 1
  test(10); // 36
  return 0;
}
