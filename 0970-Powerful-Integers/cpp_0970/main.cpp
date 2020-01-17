#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void testBound(int x, int bound) {
  Solution solution;
  cout << solution.calcMaxBound(x, bound) << endl;
}

void test(int x, int y, int bound) {
  Solution solution;
  vector<int> ans = solution.powerfulIntegers(x, y, bound);
  sort(ans.begin(), ans.end());
  for (auto &item: ans) {
    cout << item << " ";
  }
  cout << endl;
}

int main() {
  //testBound(2, 10);
  //test(2, 3, 10);  // 2,3,4,5,7,9,10
  //test(3, 5, 15);  // 2,4,6,8,10,14
  //test(2, 1, 10);  // 2 3 5 9
  test(2, 1, 1000000);  // 2 3 5 9
  return 0;
}
