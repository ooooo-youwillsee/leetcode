#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums) {
  Solution solution;
  cout << solution.singleNumber(nums) << endl;
}

int main() {
  test({3, 4, 3, 3}); // 4
  test({9, 1, 7, 9, 7, 9, 7}); // 1
  return 0;
}
