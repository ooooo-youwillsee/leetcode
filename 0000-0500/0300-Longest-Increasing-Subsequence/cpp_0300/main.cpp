#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums) {
  Solution solution;
  cout << solution.lengthOfLIS(nums) << endl;
}

int main() {
  test({1, 3, 6, 7, 9, 4, 10, 5, 6}); // 6
  test({0}); // 1
  test({0, 1}); // 2
  test({1, 0}); // 1
  test({2, 5, 3, 7, 9, 10}); // 5
  test({10, 9, 2, 5, 3, 7, 101, 18}); // 4
  return 0;
}
