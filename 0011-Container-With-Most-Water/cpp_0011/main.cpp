#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> heights) {
  Solution solution;
  cout << solution.maxArea(heights) << endl;
}

int main() {
  test({1, 8, 6, 2, 5, 4, 8, 3, 7});
  return 0;
}
