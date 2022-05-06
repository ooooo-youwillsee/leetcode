#include <iostream>
#include "Solution1.h"

void test(vector<int> candidates, int target) {
  Solution solution;
  vector<vector<int>> ans = solution.combinationSum(candidates, target);
  for (auto &group: ans) {
    for (auto &num: group) {
      cout << num << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  test({2, 3, 6, 7}, 7);
  cout << "-------------------" << endl;
  test({2, 3, 5}, 8);
  return 0;
}
