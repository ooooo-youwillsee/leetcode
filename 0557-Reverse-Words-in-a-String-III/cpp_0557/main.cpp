#include <iostream>
#include "Solution1.h"

void test(string s) {
  Solution solution;
  cout << solution.reverseWords(s) << endl;
}

int main() {
  test("Let's take LeetCode contest");
  return 0;
}
