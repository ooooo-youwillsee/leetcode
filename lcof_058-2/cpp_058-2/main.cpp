#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(string s, int k) {
  Solution solution;
  cout << solution.reverseLeftWords(s, k) << endl;
}

int main() {
  test("abcdefg", 2);
  test("lrloseumgh", 6);
  return 0;
}
