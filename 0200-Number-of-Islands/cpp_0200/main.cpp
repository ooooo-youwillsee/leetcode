#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<vector<char>> grid) {
  Solution solution;
  cout << solution.numIslands(grid) << endl;
}

int main() {
  test({
    // i * n + j
           {'1', '1', '1', '1', '0'},
           {'1', '1', '0', '1', '0'},
           {'1', '1', '0', '0', '0'},
           {'0', '0', '0', '0', '0'}
       }); // 1

  test({
           {'1', '1', '0', '0', '0'},
           {'1', '1', '0', '0', '0'},
           {'0', '0', '1', '0', '0'},
           {'0', '0', '0', '1', '1'}
       }); // 3
  return 0;
}
