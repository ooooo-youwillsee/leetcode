#include <iostream>
#include "Solution1.h"

void test(vector<int> nums) {
  Solution solution;
  cout << solution.repeatedNTimes(nums) << endl;
}

int main() {
  test({1, 2, 3, 3}); // 3
  test({2, 1, 2, 5, 3, 2});  // 2
  test({5, 1, 5, 2, 5, 3, 5, 4}); // 5
  return 0;
}
