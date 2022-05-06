#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(string paragraph, vector<string> banned) {
  Solution solution;
  cout << solution.mostCommonWord(paragraph, banned) << endl;
}

int main() {
  test("Bob hit a ball, the hit BALL flew far after it was hit.", {"hit"});
  return 0;
}
