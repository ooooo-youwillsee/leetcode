#include <iostream>
#include "Solution1.h"

void testSplit(string s) {
  Solution solution;
  for (const auto &item: solution.split(s, ".")) {
    cout << item << " ";
  }
  cout << endl;
}

void test(vector<string> domains) {
  Solution solution;
  for (const auto &item:solution.subdomainVisits(domains)) {
    cout << item << " ";
  }
  cout << endl;
}

int main() {
  //testSplit("9001 discuss.leetcode.com");
  test({"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"});
  return 0;
}
