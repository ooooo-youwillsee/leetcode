#include <iostream>
#include "Solution1.h"

void test(int n, int m) {
  Solution solution;
  cout << solution.lastRemaining(n, m) << endl;
}

int main() {
  test(5, 3);  // 3
  test(10, 17);  // 2
  return 0;
}
