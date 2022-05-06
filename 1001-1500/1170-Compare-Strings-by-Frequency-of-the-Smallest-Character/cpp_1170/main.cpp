#include <iostream>
#include "Solution1.h"

void test(vector<string> queries, vector<string> words) {
  Solution solution;
  for (auto &i: solution.numSmallerByFrequency(queries, words)) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  test({"cbd"}, {"zaaaz"}); // [1]
  test({"bbb", "cc"}, {"a", "aa", "aaa", "aaaa"});  // [1,2]
  test({"bba", "abaaaaaa", "aaaaaa", "bbabbabaab", "aba", "aa", "baab", "bbbbbb", "aab", "bbabbaabb"}, {
      "aaabbb", "aab", "babbab", "babbbb", "b", "bbbbbbbbab", "a", "bbbbbbbbbb", "baaabbaab",
      "aa"}); // [6,1,1,2,3,3,3,1,3,2]
  return 0;
}
