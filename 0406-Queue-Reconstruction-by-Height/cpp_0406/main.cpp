#include <iostream>
#include "Solution1.h"

void test(vector<vector<int>> people) {
  Solution solution;
  auto ans = solution.reconstructQueue(people);
  for (auto &p: ans) {
    cout << "[" << p[0] << "," << p[1] << "] ";
  }
  cout << endl;
}

int main() {
  test({{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}});
  return 0;
}
