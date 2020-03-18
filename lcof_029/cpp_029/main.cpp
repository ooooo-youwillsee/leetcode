#include <iostream>
#include "Solution1.h"

void test(vector<vector<int>> matrix) {
  Solution solution;
  auto ans = solution.spiralOrder(matrix);
  for (auto &num : ans) cout << num << " ";
  cout << endl;
}

int main() {
  test({
           {1, 2, 3},
           {4, 5, 6},
           {7, 8, 9}
       }); // 1,2,3,6,9,8,7,4,5

  test({
           {1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}
       }); // 1,2,3,4,8,12,11,10,9,5,6,7
  return 0;
}
