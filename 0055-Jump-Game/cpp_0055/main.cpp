#include <iostream>
#include "Solution1.h"

void test(vector<int> nums) {
  Solution solution;
  cout << solution.canJump(nums) << endl;
}

int main() {
  test({0}); // 1
  test({2, 3, 1, 1, 4}); // 1
  test({3, 2, 1, 0, 4}); // 0
  test({3, 2, 1, 1, 0, 0, 4}); // 0
  return 0;
}
