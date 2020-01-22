#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(int z) {
  Solution solution;
  CustomFunction custom_function;
  for (auto vec: solution.findSolution(custom_function, 5)) {
    cout << "[";
    for (int i = 0; i < vec.size(); ++i) {
      if (i == vec.size() - 1) {
        cout << ",";
      }
      cout << vec[i];
    }
    cout << "],";
  }
  cout << endl;
}

int main() {
  test(5);
  return 0;
}
