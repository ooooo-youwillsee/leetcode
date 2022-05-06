#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(NumArray &num_array, int queryLeft, int queryRight) {
  cout << num_array.sumRange(queryLeft, queryRight) << endl;
}
int main() {
  vector<int> vec = {-2, 0, 3, -5, 2, -1};
  NumArray num_array(vec);
  test(num_array, 0, 2);
  test(num_array, 2, 5);
  test(num_array, 0, 5);
  return 0;
}
