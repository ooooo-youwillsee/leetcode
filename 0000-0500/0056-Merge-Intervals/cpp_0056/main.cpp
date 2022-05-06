#include <iostream>
#include "Solution1.h"

void test(vector<vector<int>> nums) {
  Solution solution;
  vector<vector<int>> ans = solution.merge(nums);
  for (auto &group: ans) {
    cout << "[" << group[0] << "," << group[1] << "]" << " ";
  }
  cout << endl;
}

int main() {
  test({{1, 3}, {2, 6}, {8, 10}, {15, 18}, {16, 20}});
  return 0;
}
