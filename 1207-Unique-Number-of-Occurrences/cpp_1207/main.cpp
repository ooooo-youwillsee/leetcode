#include <iostream>
#include "Solution1.h"

void test(vector<int> nums) {
  Solution solution;
  cout << solution.uniqueOccurrences(nums) << endl;
}

int main() {
  test({1, 2}); // false
  test({-3, 0, 1, -3, 1, 1, 1, -3, 10, 0}); // true
  return 0;
}
