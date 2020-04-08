#include <iostream>
#include "Solution1.h"

void test(vector<int> nums) {
  Solution solution;
  cout << solution.reversePairs(nums) << endl;
}

int main() {
  test({7, 5, 6, 4});
  test({1, 3, 2, 3, 1});
  return 0;
}
