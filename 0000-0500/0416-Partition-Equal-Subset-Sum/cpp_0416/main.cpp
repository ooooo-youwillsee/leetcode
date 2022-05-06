#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums) {
  Solution solution;
  cout << solution.canPartition(nums) << endl;
}

int main() {

  test({1, 5, 11, 5}); // 1
  test({1, 2, 3, 5});  // 0
  return 0;
}
