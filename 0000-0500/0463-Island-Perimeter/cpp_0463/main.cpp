#include <iostream>
#include "Solution1.h"

void test(vector<vector<int>> grid) {
  Solution s;
  cout << s.islandPerimeter(grid) << endl;
}

int main() {
  test({
           {0, 1, 0, 0},
           {1, 1, 1, 0},
           {0, 1, 0, 0},
           {1, 1, 0, 0}
       });
  return 0;
}
