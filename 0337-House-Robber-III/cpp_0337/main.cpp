#include <iostream>
//#include "Solution1.h"
//#include "Solution2.h"
#include "Solution3.h"

void test(vector<int> nums) {
  Solution solution;
  cout << solution.rob(new TreeNode(nums)) << endl;
}

int main() {
  test({3, 2, 3, INT_MAX, 3, INT_MAX, 1});
  return 0;
}
