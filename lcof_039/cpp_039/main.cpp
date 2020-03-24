#include <iostream>
//#include "Solution1.h"
//#include "Solution2.h"
#include "Solution3.h"

void test(vector<int> nums) {
  Solution solution;
  cout << solution.majorityElement(nums) << endl;
}

int main() {
  test({4, 5, 4});
  test({1});
  test({1, 1, 2});
  test({2, 2});
  test({1, 2, 3, 2, 2, 2, 5, 4, 2});
  return 0;
}
