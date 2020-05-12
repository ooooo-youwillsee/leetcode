#include <iostream>
#include "Solution1.h"

void test(vector<int> nums) {
  Solution solution;
  auto ans = solution.constructArr(nums);
  for (auto &item: ans) cout << item << " ";
  cout << endl;
}

int main() {
  test({1, 2, 3, 4, 5});
  test({1, 2, 0, 4, 5});
  return 0;
}
