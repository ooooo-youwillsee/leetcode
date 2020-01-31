#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(string s) {
  Solution solution;
  cout << solution.toGoatLatin(s) << endl;
}

int main() {
  test("I speak Goat Latin");
  test("The quick brown fox jumped over the lazy dog");
  return 0;
}
