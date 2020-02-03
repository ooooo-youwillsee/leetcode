#include <iostream>
#include "Solution1.h"

void test(string s) {
  Solution solution;
  cout << solution.freqAlphabets(s) << endl;
}

int main() {
  test("10#11#12"); // "jkab"
  test("1326#"); // "acz"
  test("25#"); // "y"
  test("12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"); // "abcdefghijklmnopqrstuvwxyz"
  return 0;
}
