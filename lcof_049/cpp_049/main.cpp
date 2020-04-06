#include <iostream>
//#include "Solution1.h"
//#include "Solution2.h"
#include "Solution3.h"

void test(int n) {
  Solution solution;
  cout << solution.nthUglyNumber(n) << endl;
}

int main() {
  test(1); // 1
  test(2); // 1
  test(10); // 12
  return 0;
}
