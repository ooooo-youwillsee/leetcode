#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums, int k) {
  Solution solution;
  for (auto item: solution.topKFrequent(nums, k)) {
    cout << item << " ";
  }
  cout << endl;
}

int main() {
  test({1, 1, 1, 2, 2, 3}, 2);
  test({1}, 1);
  return 0;
}
