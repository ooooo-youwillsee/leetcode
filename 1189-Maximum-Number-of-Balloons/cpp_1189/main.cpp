#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(string s) {
  Solution solution;
  cout << solution.maxNumberOfBalloons(s) << endl;
}

int main() {
  test("nlaebolko"); // 1
  test("loonbalxballpoon"); // 2
  test("leetcode"); // 0
  return 0;
}
