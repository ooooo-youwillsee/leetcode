#include <iostream>
//#include "Solution1.h"
//#include "Solution2.h"
#include "Solution3.h"

void test(vector<int> nums, int k) {
  Solution solution;
  auto ans = solution.getLeastNumbers(nums, k);
  for (auto &n: ans) cout << n << " ";
  cout << endl;
}

int main() {
  test({3, 2, 1}, 2);
  test({0, 1, 2, 1}, 1);
  test({0, 0, 2, 3, 2, 1, 1, 2, 0, 4}, 10);
  test({0, 0, 2, 3, 2, 1, 1, 2, 0, 4}, 9);
  return 0;
}
