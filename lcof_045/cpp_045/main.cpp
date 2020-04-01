#include <iostream>
#include "Solution1.h"

void test(vector<int> nums) {
  Solution solution;
  cout << solution.minNumber(nums) << endl;
}

int main() {
  test({121, 12});
  test({128, 12});
  test({10, 2}); // 102
  test({3, 30, 34, 5, 9}); // 3033459
  test({3, 0, 34, 5, 9}); // 3033459
  return 0;
}
