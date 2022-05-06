#include <iostream>
#include "Solution1.h"

void test(int n) {
  Solution solution;
  cout << solution.numTrees(n) << endl;
}

int main() {
  test(3); // 5
  test(4); // 14
  return 0;
}
