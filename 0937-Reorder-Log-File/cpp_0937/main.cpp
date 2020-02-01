#include <iostream>
#include "Solution1.h"

void test(vector<string> logs) {
  Solution solution;
  for (auto &item: solution.reorderLogFiles(logs)) {
    cout << item << "->";
  }
  cout << endl;
}

int main() {
  test({"a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo"});
  return 0;
}
