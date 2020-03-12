#include <iostream>
#include "Solution1.h"

void test(uint32_t n) {
  Solution solution;
  cout << solution.hammingWeight(n) << endl;
}

int main() {
  test(11);  // 3
  return 0;
}
