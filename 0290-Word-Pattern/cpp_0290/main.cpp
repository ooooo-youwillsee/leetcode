#include <iostream>
#include "Solution1.h"

void testSplit(string str) {
  Solution s;
  vector<string> res = s.split(str, " ");
  for (auto &item: res) {
    cout << item << " ";
  }
  cout << endl;
}

void test(string pattern, string str) {
  Solution s;
  //testSplit(str);
  cout << s.wordPattern(pattern, str) << endl;
}

int main() {

  test("e", "erueka"); // 1
  test("aaa", "aa aa aa aa"); // 0
  test("abba", "dog cat cat dog"); // 1
  test("abba", "dog cat cat fish"); // 0
  test("aaaa", "dog cat cat dog"); // 0
  test("abba", "dog dog dog dog"); //0
  return 0;
}