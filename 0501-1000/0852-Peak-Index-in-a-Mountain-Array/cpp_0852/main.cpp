#include <iostream>
#include "Solution1.h"

void test(vector<int> nums) {
  Solution solution;
  cout << solution.peakIndexInMountainArray(nums) << endl;
}

int main() {
  test({0, 1, 0}); // 1
  test({0, 2, 1, 0}); // 1
  test({0, 1, 2, 0}); // 2
  return 0;
}
