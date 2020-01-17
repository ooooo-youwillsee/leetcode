#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(int x) {
  Solution solution;
  cout << solution.isPerfectSquare(x) << endl;
}

int main() {
  test(16); // 1
  test(14); // 0
  test(2147483647); // 0
  test(1); // 1
  test(5); // 0
  test(6); // 0
  test(7); // 0
  test(8); // 0
  test(104976); // 1
  return 0;
}
