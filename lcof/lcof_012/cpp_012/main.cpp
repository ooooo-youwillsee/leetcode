#include <iostream>
#include "Solution1.h"

void test(vector<vector<char>> board, string word) {
  Solution solution;
  cout << solution.exist(board, word) << endl;
}

int main() {
  test({
           {'b', 'a'}
       }, "ab");
  test({
           {'A', 'B', 'C', 'E'},
           {'S', 'F', 'C', 'S'},
           {'A', 'D', 'E', 'E'}
       }, "ABCCED");
  return 0;
}
