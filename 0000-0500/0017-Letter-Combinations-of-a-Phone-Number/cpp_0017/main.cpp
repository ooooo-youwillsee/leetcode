#include <iostream>
#include "Solution1.h"

void test(string digits) {
  Solution solution;
  for (auto item: solution.letterCombinations(digits)) {
    cout << item << " ";
  }
  cout << endl;
}

int main() {
  test("23");
  return 0;
}
