#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums, int target) {
  Solution solution;
  cout << solution.search(nums, target) << endl;
}

int main() {
  test({}, 0); // -1
  test({1}, 0); // -1
  test({1, 2}, 0); // -1
  test({2, 1}, 1);  // 1
  test({1, 3, 2}, 1);  // 0
  test({1, 4, 2}, 3);  // -1
  test({5, 1, 3}, 1);  // 1
  test({4, 5, 6, 7, 0, 1, 2}, 0); // 4
  test({4, 5, 6, 7, 0, 1, 2}, 3); // -1
  return 0;
}
