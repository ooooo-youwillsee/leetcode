#include <iostream>
//#include "Solution1.h"
//#include "Solution2.h"
#include "Solution3.h"

void test(vector<int> nums) {
  Solution solution;
  for (auto &num: solution.findDisappearedNumbers(nums)) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {
  test({4, 3, 2, 7, 8, 2, 3, 1});
  return 0;
}
