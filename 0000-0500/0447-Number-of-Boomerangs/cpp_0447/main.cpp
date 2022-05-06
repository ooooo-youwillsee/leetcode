#include <iostream>
#include "Solution1.h"

void test(vector<vector<int>> vec) {
  Solution s;
  cout << s.numberOfBoomerangs(vec) << endl;
}

int main() {
  test({{0, 0}, {1, 0}, {2, 0}});
  return 0;
}
