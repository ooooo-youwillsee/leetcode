#include <iostream>
#include "Solution1.h"

void test(int m, int n, int k) {
  Solution solution;
  cout << solution.movingCount(m, n, k) << endl;
}

int main() {
  test(2, 3, 1); // 3
  test(7, 2, 3); // 7
  test(3, 1, 0); // 1
  test(38, 15, 9); // 135
  return 0;
}
