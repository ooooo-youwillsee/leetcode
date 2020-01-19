#include <iostream>
#include "Solution1.h"

void test(vector<int> nums, int target) {
  Solution solution;
  cout << solution.search(nums, target) << endl;
}

int main() {
  test({-1, 0, 3, 5, 9, 12}, 9); // 4
  test({-1, 0, 3, 5, 9, 12}, 2); // -1
  return 0;
}
