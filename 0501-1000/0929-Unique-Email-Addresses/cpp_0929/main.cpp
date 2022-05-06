#include <iostream>
#include "Solution1.h"

void test(vector<string> vec) {
  Solution solution;
  cout << solution.numUniqueEmails(vec) << endl;
}

int main() {
  test({"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"}); // 2
  return 0;
}
