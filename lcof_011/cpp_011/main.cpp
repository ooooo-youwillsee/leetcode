#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums) {
  Solution solution;
  cout << solution.minArray(nums) << endl;
}

int main() {
  test({10, 10, 1, 10}); // 1
  test({10, 1, 10, 10, 10}); // 1
  test({3, 1, 3}); // 1
  test({3, 4, 5, 1, 2}); // 1
  test({2, 2, 2, 0, 1}); // 0
  test({0, 1}); // 0
  test({2, 0, 1}); // 0
  test({1, 3, 5}); // 1
  return 0;
}
