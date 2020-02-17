#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(string s, vector<string> wordDict){
  Solution solution;
  cout<<solution.wordBreak(s, wordDict)<<endl;
}

int main() {
  test("leetcode", {"leet", "code"}); // true
  test("applepenapple", {"apple", "pen"}); // true
  test("catsandog", {"cats", "dog", "sand", "and", "cat"}); // false
  return 0;
}
