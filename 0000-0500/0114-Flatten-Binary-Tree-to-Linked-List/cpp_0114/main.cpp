#include <iostream>
#include "Solution1.h"

void test(vector<int> nums) {
  Solution solution;
  solution.flatten(new TreeNode(nums));
}

int main() {
  test({1, 2, 5, 3, 4, INT_MAX, 6});
  return 0;
}
