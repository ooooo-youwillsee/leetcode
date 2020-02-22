#include <iostream>
#include "Solution1.h"

void test(vector<vector<int>> matrix, vector<int> targets) {
  Solution solution;
  for (auto &target: targets) {
    cout << solution.searchMatrix(matrix, target) << " ";
  }
  cout << endl;
}

int main() {
  test({
           {1, 4, 7, 11, 15},
           {2, 5, 8, 12, 19},
           {3, 6, 9, 16, 22},
           {10, 13, 14, 17, 24},
           {18, 21, 23, 26, 30}
       }, {5, 20});

  return 0;
}
