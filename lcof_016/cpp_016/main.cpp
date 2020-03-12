#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(double x, int n) {
  Solution solution;
  cout << solution.myPow(x, n) << endl;
}

int main() {
  test(2.0, 10);
  test(2.0, -2);
  test(2.1, 3);
  test(1, -2147483648);
  return 0;
}
