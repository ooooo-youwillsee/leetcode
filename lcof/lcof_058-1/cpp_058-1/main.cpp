#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(string s) {
  Solution solution;
  cout << solution.reverseWords(s) << endl;
}

int main() {
  test("  hello world!  ");
  test("the sky is blue");
  test("a good   example");
  return 0;
}
