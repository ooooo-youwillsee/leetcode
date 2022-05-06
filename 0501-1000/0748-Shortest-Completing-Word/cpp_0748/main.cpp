#include <iostream>
#include "Solution1.h"

void test(string licensePlate, vector<string> words) {
  Solution s;
  cout << s.shortestCompletingWord(licensePlate, words) << endl;
}

int main() {
  test("1s3 PSt", {"step", "steps", "stripe", "stepple"});
  test("1s3 456", {"looks", "pest", "stew", "show"});
  return 0;
}