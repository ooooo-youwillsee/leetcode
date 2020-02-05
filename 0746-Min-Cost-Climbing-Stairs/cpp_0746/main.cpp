#include <iostream>
#include "Solution1.h"

void test(vector<int> costs) {
  Solution solution;
  cout << solution.minCostClimbingStairs(costs) << endl;
}

int main() {
  test({10, 15});
  test({10, 15, 20});
  test({1, 100, 1, 1, 1, 100, 1, 1, 100, 1});
  return 0;
}
