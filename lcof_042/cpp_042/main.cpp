#include <iostream>
#include "Solution1.h"

void test(vector<int> nums) {
  Solution solution;
  cout << solution.maxSubArray(nums) << endl;
}

int main() {
  test({1});
  test({-1, -2});
  test({-2, 1, -3, 4, -1, 2, 1, -5, 4});
  return 0;
}
