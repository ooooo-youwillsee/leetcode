#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums) {
  Solution solution;
  for (auto &item: solution.findErrorNums(nums)) {
    cout << item << " ";
  }
  cout << endl;
}

int main() {
  test({1, 2, 2, 4});
  test({3, 2, 3, 4, 6, 5});
  return 0;
}
