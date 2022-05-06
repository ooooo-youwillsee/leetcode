#include <iostream>
#include "Solution1.h"

void testSplit(string s) {
  Solution solution;
  for (auto &item: solution.split(s)) {
    cout << item << " ";
  }
  cout << endl;
}

void test(string s1, string s2) {
  Solution solution;
  for (auto &item: solution.uncommonFromSentences(s1, s2)) {
    cout << item << " ";
  }
  cout << endl;
}

int main() {
  //testSplit("this apple is sweet");
  test("this apple is sweet", "this apple is sour");
  test("apple apple", "banana");
  return 0;
}
