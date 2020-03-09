#include <iostream>
#include "Solution1.h"

void test(vector<int> nums) {
  Solution solution;
  for (auto &n: nums)
    cout << solution.numWays(n) << endl;
}

int main() {
  test({0, 1, 2, 7});
  return 0;
}
