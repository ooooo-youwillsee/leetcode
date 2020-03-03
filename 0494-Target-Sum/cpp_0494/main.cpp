#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums, int S) {
  Solution solution;
  cout << solution.findTargetSumWays(nums, S) << endl;
}

int main() {
  test({1, 1, 1, 1, 1}, 3); // 5
  return 0;
}
