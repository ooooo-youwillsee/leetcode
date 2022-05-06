#include <iostream>
#include "Solution1.h"

void test(vector<int> nums) {
  Solution solution;
  vector<vector<int>> ans = solution.permute(nums);
  for (auto &group: ans) {
    for (auto &item: group) {
      cout << item << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  test({1, 2, 3});
  return 0;
}
