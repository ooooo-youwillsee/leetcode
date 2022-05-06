#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<vector<int>> nums) {
  Solution solution;
  solution.rotate(nums);
  for (const auto &item : nums) {
    for (const auto &num : item) {
      cout << num << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  test({
           {1, 2, 3},
           {4, 5, 6},
           {7, 8, 9}
       });
  return 0;
}
