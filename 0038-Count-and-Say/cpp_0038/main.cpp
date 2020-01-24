#include <iostream>
#include "Solution1.h"

void test(int n) {
  Solution solution;
  cout << solution.countAndSay(n) << endl;
}

int main() {
  test(1); // "1"
  test(4); // "1211"
  test(5); // "111221"
  return 0;
}
