#include <iostream>
#include "Solution1.h"

void test(int n, int m) {
  Solution solution;
  cout << solution.add(n, m) << endl;
}

int main() {
  test(1, 2);
  test(-1, 2);
  test(12, 9);
  return 0;
}
