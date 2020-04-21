#include <iostream>
#include "Solution1.h"

void test(vector<int> nums) {
  Solution solution;
  cout << solution.isStraight(nums) << endl;
}

int main() {
  test({1, 2, 3, 4, 5});
  test({0, 0, 1, 2, 5});
  return 0;
}
