#include <iostream>
//#include "Solution1.h"
//#include "Solution2.h"
#include "Solution3.h"

void test(vector<int> nums) {
  Solution solution;
  cout << solution.missingNumber(nums) << endl;
}

int main() {
  test({0, 2}); // 1
  test({1, 2, 3}); // 0
  test({1, 2}); // 0
  test({0}); // 1
  test({1}); // 0
  test({0, 1, 3}); // 2
  test({0, 1, 2, 3, 4, 5, 6, 7, 9}); // 8
  return 0;
}
