#include <iostream>
#include "Solution1.h"

void test(vector<int> nums1, vector<int> nums2) {
  Solution solution;
  cout << solution.isSubStructure(new TreeNode(nums1), new TreeNode(nums2)) << endl;
}

int main() {
  test({10, 12, 6, 8, 3, 11}, {10, 12, 6, 8}); // 1
  return 0;
}
