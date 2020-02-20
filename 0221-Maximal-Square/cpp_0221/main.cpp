#include <iostream>
#include "Solution1.h"

void test(vector<vector<char>> matrix) {
  Solution solution;
  cout << solution.maximalSquare(matrix) << endl;
}

int main() {
  test({
           {'1', '0', '1', '0', '0'},
           {'1', '0', '1', '1', '1'},
           {'1', '1', '1', '1', '1'},
           {'1', '0', '0', '1', '0'}
       });
  test({
           {'1'},
       });
  return 0;
}
