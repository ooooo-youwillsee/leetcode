#include <iostream>
#include "Solution1.h"

void test(vector<int> nums) {
  Solution solution;
  vector<int> ans = solution.productExceptSelf(nums);
  for (auto &num : ans) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {
  test({0, 0});
  test({0, 1});
  test({1, 2, 3, 4});
  return 0;
}
