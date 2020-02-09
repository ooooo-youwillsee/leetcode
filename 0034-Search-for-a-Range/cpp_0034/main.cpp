#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums, int target) {
  Solution solution;
  for (auto i:solution.searchRange(nums, target)) {
    cout << i << " ";
  }
  cout << endl;
}

void testBound(vector<int> nums, int target) {
  Solution solution;
  cout << solution.findBound(nums, target, false) << endl;
}

int main() {
  test({}, 8);
  test({5}, 8);
  test({1}, 1);
  test({5, 7, 7, 8, 8, 10}, 8);
  test({5, 7, 7, 8, 8, 10}, 6);

  /**
   * testBound
   */
  //testBound({}, 8);
  //testBound({5}, 8);
  //testBound({1}, 1);
  //testBound({5, 7, 7, 8, 8, 10}, 8);
  //testBound({5, 7, 7, 8, 8, 10}, 6);
  return 0;
}
