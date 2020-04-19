#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums, int k) {
  Solution solution;
  auto ans = solution.maxSlidingWindow(nums, k);
  for (auto &num :ans) cout << num << " ";
  cout<<endl;
}

int main() {
  test({1, 3, -1, -3, 5, 3, 2, 2}, 3);
  test({1, 3, -1, -3, 5, 3, 6, 7}, 3);
  return 0;
}
