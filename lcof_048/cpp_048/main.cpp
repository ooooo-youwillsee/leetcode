#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(string s) {
  Solution solution;
  cout << solution.lengthOfLongestSubstring(s) << endl;
}

int main() {
  test("pwwkew");  // 3
  test("abcabcbb");  // 3
  test("bbbbb");  // 1
  test("");  // 0
  test("abc");  // 3
  return 0;
}
