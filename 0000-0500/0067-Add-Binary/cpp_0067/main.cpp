#include <iostream>
#include "Solution1.h"

void test(string s1, string s2) {
  Solution solution;
  cout << solution.addBinary(s1, s2) << endl;

}
int main() {
  test("11", "1"); // "100"
  test("1010", "1011"); // "10101"
  return 0;
}
