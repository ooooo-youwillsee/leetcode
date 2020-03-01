#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(string s, string p) {
  Solution solution;
  auto ans = solution.findAnagrams(s, p);
  for (auto &i: ans) cout << i << " ";
  cout << endl;
}

int main() {
  test("", "a");
  test("cbaebabacd", "abc");
  test("aa", "bb");
  test("abab", "ab");
  return 0;
}
