#include <iostream>
//#include "Solution1.h"
//#include "Solution2.h"
#include "Solution3.h"

void test(vector<int> nums) {
  Solution solution;
  cout << solution.findDuplicate(nums) << endl;
}

int main() {
  test({1, 3, 4, 2, 2}); // 2
  test({3, 1, 3, 4, 2}); // 3
  return 0;
}
