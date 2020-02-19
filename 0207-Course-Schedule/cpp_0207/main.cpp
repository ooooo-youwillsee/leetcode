#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(int num, vector<vector<int>> prerequisites) {
  Solution solution;
  cout << solution.canFinish(num, prerequisites) << endl;
}

int main() {
  test(2, {{1, 0}}); // 1
  test(2, {{1, 0}, {0, 1}}); // 0
  return 0;
}
