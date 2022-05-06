#include <iostream>
#include "Solution2.h"

void test(vector<int> nums) {
  Solution solution;
  solution.inorderTraversal(new TreeNode(nums));
}

int main() {
  test({1, INT_MAX, 2, 3});
  return 0;
}
