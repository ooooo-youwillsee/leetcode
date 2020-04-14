#include <iostream>
#include "Solution1.h"

void test(vector<int> nums) {
  Solution solution;
  auto ans = solution.singleNumbers(nums);
  for (auto &num :ans) cout << num << " ";
  cout << endl;
}

int main() {
  test({4, 1, 4, 6}); // 1, 6
  test({1, 2, 10, 4, 1, 4, 3, 3}); // 2, 10
  return 0;
}
