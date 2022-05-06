#include <iostream>
//#include "Solution1.h"
//#include "Solution2.h"
#include "Solution3.h"

void test(vector<int> nums, int target) {
  Solution solution;
  cout << solution.search(nums, target) << endl;
}

int main() {
  test({2, 2}, 2);
  test({5, 7, 7, 8, 8, 10}, 8);
  test({5, 7, 7, 8, 8, 10}, 0);
  return 0;
}
