#include <iostream>
//#include "Solution1.h"
//#include "Solution2.h"
#include "Solution3.h"

void test(int x) {
  Solution solution;
  cout << solution.arrangeCoins(x) << endl;
}

int main() {
  test(5);  // 2
  test(8);  // 3
  test(2147483647);  // 65535
  return 0;
}
