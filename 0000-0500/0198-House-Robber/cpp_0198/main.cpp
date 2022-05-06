#include <iostream>
#include "Solution1.h"

void test(vector<int> nums) {
  Solution solution;
  cout << solution.rob(nums) << endl;
}

int main() {
  test({1, 2, 3, 1});
  test({2, 7, 9, 3, 1});
  return 0;
}
