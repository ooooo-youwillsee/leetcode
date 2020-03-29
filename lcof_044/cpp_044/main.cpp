#include <iostream>
#include "Solution1.h"

void test(int n) {
  Solution solution;
  cout << solution.findNthDigit(n) << endl;
}

int main() {
  test(20); // 1
  test(11); // 0
  test(3); // 3
  test(13); // 1
  test(19); // 4
  test(1000000000); // 1
  return 0;
}
