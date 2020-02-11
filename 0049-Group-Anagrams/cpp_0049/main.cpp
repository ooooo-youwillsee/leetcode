#include <iostream>
#include "Solution1.h"

void test(vector<string> strs) {
  Solution solution;
  vector<vector<string>> ans = solution.groupAnagrams(strs);
  for (auto &group: ans) {
    for (auto &str: group) {
      cout << str << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  test({"eat", "tea", "tan", "ate", "nat", "bat"});
  return 0;
}
