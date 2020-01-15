#include <iostream>
#include "SolutIon1.h"

void test(string s1, string s2) {
  Solution solution;
  cout << solution.numJewelsInStones(s1, s2) << endl;
}

int main() {
  test("aA", "aAAbbbb");
  return 0;
}
