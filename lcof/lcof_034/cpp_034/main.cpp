#include <iostream>
#include "Solution1.h"

void test(vector<int> nums, int sum) {
  Solution solution;
  auto ans = solution.pathSum(new TreeNode(nums), sum);
  for (auto &g: ans) {
    for (auto &n: g) cout << n << " ";
    cout << endl;
  }
  cout << endl;
}

int main() {
  test({5, 4, 8, 11, INT_MAX, 13, 4, 7, 2, INT_MAX, INT_MAX, 5, 1}, 22);
  test({-2, INT_MAX, -3}, -5);
  return 0;
}
