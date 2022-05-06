#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<vector<int>> grid) {
  Solution solution;
  cout << solution.maxValue(grid) << endl;
}

int main() {
  test({
           {1, 3, 1},
           {1, 5, 1},
           {4, 2, 1}
       }); // 12
  return 0;
}
