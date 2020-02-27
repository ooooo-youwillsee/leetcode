#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(string s) {
  Solution solution;
  cout << solution.decodeString(s) << endl;
}

int main() {
  test("3[a]2[bc]");  // "aaabcbc"
  test("100[leetcode]"); //  "leetcode *100"
  test("3[a2[c]]"); // "accaccacc"
  test("2[abc]3[cd]ef"); //  "abcabccdcdcdef"
  return 0;
}
