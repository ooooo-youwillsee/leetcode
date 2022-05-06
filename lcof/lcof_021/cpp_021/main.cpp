#include <iostream>
#include "Solution1.h"

void test(vector<int> nums) {
  Solution solution;
  auto ans = solution.exchange(nums);
  for (auto num: nums) cout << num << " ";
  cout << endl;
}

int main() {
  test({1, 2, 3, 4});
  test({1, 3, 5});
  test({1, 3, 5, 4, 6});
  test({1, 3, 5, 4, 7});
  test({2, 4, 6});
  return 0;
}
