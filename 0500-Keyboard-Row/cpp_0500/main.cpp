#include <iostream>
#include "Solution1.h"

void test(vector<string> vec) {
  Solution solution;
  for (const auto &item:solution.findWords(vec)) {
    cout << item << " ";
  }
  cout << endl;
}

int main() {
  test({"Hello", "Alaska", "Dad", "Peace"});
  test({"abdfs", "cccd", "a", "qwwewm"});
  test({"qz", "wq", "asdddafadsfa", "adfadfadfdassfawde"});
  return 0;
}
