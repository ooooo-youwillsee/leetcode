#include <iostream>
#include "Solution1.h"

void test(int n) {
  Solution solution;
  cout << solution.firstBadVersion(n) << endl;
}

int main() {
  test(5);
  test(2126753390);
  return 0;
}
