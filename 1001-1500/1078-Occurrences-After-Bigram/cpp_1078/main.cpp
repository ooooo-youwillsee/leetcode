#include <iostream>
#include "Solution1.h"

void testSplit(string s) {
  Solution solution;
  for (auto &item: solution.split(s)) {
    cout << item << " ";
  }
  cout << endl;
}

void test(string s, string first, string second) {
  Solution solution;
  for (auto &item: solution.findOcurrences(s, first, second)) {
    cout << item << " ";
  }
  cout << endl;
}

int main() {
  //testSplit("alice is a good girl she is a good student");
  test("alice is a good girl she is a good student", "a", "good");
  test("we will we will rock you", "we", "will");
  return 0;
}
