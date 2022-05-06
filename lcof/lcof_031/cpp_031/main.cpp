#include <iostream>
#include "Solution1.h"

void test(vector<int> pushed, vector<int> popped) {
  Solution solution;
  cout << solution.validateStackSequences(pushed, popped) << endl;
}

int main() {
  test({1, 2, 3, 4, 5}, {4, 5, 3, 2, 1}); // 1
  test({1, 2, 3, 4, 5}, {4, 3, 5, 1, 2}); // 0
  return 0;
}
