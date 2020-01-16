#include <iostream>
#include "Solution1.h"

void test(vector<string> words) {
  Solution solution;
  for (auto &item: solution.commonChars(words)) {
    cout << item << " ";
  }
  cout << endl;
}

int main() {
  //std::cout << string(1, 'c') << std::endl;
  test({"bella", "label", "roller"});
  test({"cool", "lock", "cook"});
  return 0;
}
