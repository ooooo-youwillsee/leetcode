#include <iostream>
#include "Solution1.h"

void test(vector<int> nums, int target) {
  Solution solution;
  auto ans = solution.twoSum(nums, target);
  cout << ans[0] << " " << ans[1] << endl;
}

int main() {
  test({16, 16, 18, 24, 30, 32}, 48);
  test({2, 7, 11, 15}, 9);
  test({10, 26, 30, 31, 47, 60}, 40);
  return 0;
}
